#include "MyNet.h"

MMyLib::MySessionBase::MySessionBase(boost::asio::io_service& ios): sock(new ip::tcp::socket(ios))
{}

MMyLib::MySessionBase::~MySessionBase()
{}

MMyLib::MyServSessionBase::MyServSessionBase(boost::asio::io_service& ios): MySessionBase(ios)
{}

MMyLib::MyServSessionBase::~MyServSessionBase()
{}

MMyLib::MyServSession1::MyServSession1(boost::asio::io_service& ios): MyServSessionBase(ios)
{}

MMyLib::MyServSession1::~MyServSession1()
{}

void MMyLib::MyServSession1::start()
{
	//cout<< "recive from "<< sock->remote_endpoint().address()<< endl;
	std::shared_ptr<vector<char> > str(new vector<char>(100, 0));
	sock->async_read_some(buffer(*str), boost::bind(&MyServSession1::read_handler, this, boost::asio::placeholders::error, str));
}

void MMyLib::MyServSession1::write_handler(const boost::system::error_code& ec)
{
	if (ec)
		return;
	std::shared_ptr<vector<char> > str(new vector<char>(100, 0));
	sock->async_read_some(buffer(*str), boost::bind(&MyServSession1::read_handler, this, boost::asio::placeholders::error, str));
}

void MMyLib::MyServSession1::read_handler(const boost::system::error_code& ec, std::shared_ptr<vector<char> > str)
{
	if (ec)
		return;
	cout<< &(*str)[0]<< endl;
	sock->async_write_some(buffer("hello asio"), boost::bind(&MyServSession1::write_handler, this, boost::asio::placeholders::error));
}

MMyLib::MyServer::MyServer(io_service& ios): ios(ios), acceptor(ios, ip::tcp::endpoint(ip::tcp::v4(), SERVPORT))
{
	start();
}

void MMyLib::MyServer::start()
{
	std::shared_ptr<MyServSession1> new_session(new MyServSession1(ios));
	//MyServSession1* new_session = new MyServSession1(ios);
    acceptor.async_accept(*(new_session->sock), boost::bind(&MyServer::accept_handler, this, new_session, boost::asio::placeholders::error));
}

void MMyLib::MyServer::accept_handler(std::shared_ptr<MyServSession1> new_session, const boost::system::error_code& ec)
{
	if (ec)
		return;
    new_session->start();
    start();
}











//MyClient
MMyLib::MyClient::MyClient(io_service& io): ios(io), ep(ip::address::from_string(CLTIP), CLTPORT)
{
	start();
}

void MMyLib::MyClient::start()
{
	sock_pt sock(new ip::tcp::socket(ios));
	sock->async_connect(ep, boost::bind(&MyClient::conn_handler, this, boost::asio::placeholders::error, sock));
}

void MMyLib::MyClient::conn_handler(const system::error_code& ec, sock_pt sock)
{
	if(ec)
		return;
	//cout<< "recive from "<< sock->remote_endpoint().address()<< endl;
	//std::shared_ptr<vector<char> > str(new vector<char>(100, 0));
	//sock->async_read_some(buffer(*str), boost::bind(&MyClient::read_handler, this, boost::asio::placeholders::error, str));
	sock->async_write_some(buffer("123"), boost::bind(&MyClient::write_handler, this, boost::asio::placeholders::error, sock));
}

void MMyLib::MyClient::write_handler(const boost::system::error_code& ec, sock_pt sock)
{
	std::shared_ptr<vector<char> > str(new vector<char>(100, 0));
	sock->async_read_some(buffer(*str), boost::bind(&MyClient::read_handler, this, boost::asio::placeholders::error, str));
}

void MMyLib::MyClient::read_handler(const system::error_code& ec, std::shared_ptr<vector<char> > str)
{
	if(ec)
		return;
	cout<< &(*str)[0]<< endl<< endl;
}


