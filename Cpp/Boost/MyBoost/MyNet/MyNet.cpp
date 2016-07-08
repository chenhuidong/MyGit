#include "MyNet.h"

//MyServer
MMyLib::MyServer::MyServer(io_service& io): ios(io), acceptor(ios, ip::tcp::endpoint(ip::tcp::v4(), MYPORT))
{
	start();
}

void MMyLib::MyServer::start()
{
	sock_pt sock(new ip::tcp::socket(ios));
	acceptor.async_accept(*sock, boost::bind(&MyServer::accept_handler, this, boost::asio::placeholders::error, sock));		
}

void MMyLib::MyServer::accept_handler(const boost::system::error_code& ec, sock_pt sock)
{
	if(ec)
		return ;
	cout<< "clients:";
	cout<< sock->remote_endpoint().address()<< endl;
	sleep(20);
	sock->async_write_some(buffer("hello asio"), \
		boost::bind(&MyServer::write_handler, this, boost::asio::placeholders::error));

	start();
}

void MMyLib::MyServer::write_handler(const boost::system::error_code&)
{
	cout<< "send msg complete."<< endl;
}


//MyClient
MMyLib::MyClient::MyClient(io_service& io): ios(io), ep(ip::address::from_string("127.0.0.1"), MYPORT)
{
	start();
}

void MMyLib::MyClient::start()
{
	sock_pt sock(new ip::tcp::socket(ios));
	sock->async_connect(ep, boost::bind(&client::conn_handler, this, boost::asio::placeholders::error, sock));
}

void MMyLib::MyClient::conn_handler(const system::error_code& ec, sock_pt sock)
{
	if(ec)
		return;

	cout<< "recive from "<< sock->remote_endpoint().address()<< endl;
	std::shared_ptr<vector<char> > str(new vector<char>(100, 0));

	sock->async_read_some(buffer(*str), boost::bind(&client::read_handler, this, boost::asio::placeholders::error, str));
}

void MMyLib::MyClient::read_handler(const system::error_code& ec, std::shared_ptr<vector<char> > str)
{
	if(ec)
		return;

	cout<< &(*str)[0]<< endl<< endl;
}
