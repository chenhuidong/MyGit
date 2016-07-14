#include "MyNet.h"

MMyLib::MySessionBase::MySessionBase(boost::asio::io_service& ios): m_oSocket(new ip::tcp::socket(ios))
{}

MMyLib::MySessionBase::~MySessionBase()
{}

//MyServerSession
MMyLib::MyServSession1::MyServSession1(boost::asio::io_service& ios): MySessionBase(ios)
{}

MMyLib::MyServSession1::~MyServSession1()
{}

void MMyLib::MyServSession1::start()
{
	LOG_INFO<< "recive from "<< m_oSocket->remote_endpoint().address()<< ":"<< m_oSocket->remote_endpoint().port()<< endl;
	boost::shared_ptr<vector<char> > str(new vector<char>(100, 0));
	m_oSocket->async_read_some(buffer(*str), boost::bind(&MyServSession1::read_handler, shared_from_this(), boost::asio::placeholders::error, str));
}

void MMyLib::MyServSession1::write_handler(const boost::system::error_code& ec)
{
	if (ec)
		return;
	boost::shared_ptr<vector<char> > str(new vector<char>(100, 0));
	m_oSocket->async_read_some(buffer(*str), boost::bind(&MMyLib::MyServSession1::read_handler, shared_from_this(), boost::asio::placeholders::error, str));
}

void MMyLib::MyServSession1::read_handler(const boost::system::error_code& ec, boost::shared_ptr<vector<char> > str)
{
	if (ec)
		return;
	LOG_INFO<< &(*str)[0]<< endl;
	m_oSocket->async_write_some(buffer("hello asio"), boost::bind(&MyServSession1::write_handler, shared_from_this(), boost::asio::placeholders::error));
}

//MyServer
MMyLib::MyServer::MyServer(io_service& in_oIos): m_oIos(in_oIos), m_oAcceptor(in_oIos, ip::tcp::endpoint(ip::tcp::v4(), SERVPORT))
{
	start();
}

MMyLib::MyServer::~MyServer()
{}

void MMyLib::MyServer::start()
{
	boost::shared_ptr<MMyLib::MyServSession1> new_session = boost::make_shared<MMyLib::MyServSession1>(m_oIos);
	m_oAcceptor.async_accept(*(new_session->m_oSocket), boost::bind(&MyServer::accept_handler, this, new_session, boost::asio::placeholders::error));
}
/*
void MMyLib::MyServer::accept_handler(boost::shared_ptr<MyServSession1> new_session, const boost::system::error_code& ec)
{
	if (ec)
		return;
    new_session->start();
    start();
}
*/

//MyCltSession
MMyLib::MyCltSession1::MyCltSession1(boost::asio::io_service& ios): MySessionBase(ios)
{}

MMyLib::MyCltSession1::~MyCltSession1()
{}

void MMyLib::MyCltSession1::start()
{
	m_oSocket->async_write_some(buffer("123"), boost::bind(&MyCltSession1::write_handler, shared_from_this(), boost::asio::placeholders::error));
}

void MMyLib::MyCltSession1::write_handler(const boost::system::error_code& ec)
{
	if(ec)
		return;
	boost::shared_ptr<vector<char> > str(new vector<char>(100, 0));
	m_oSocket->async_read_some(buffer(*str), boost::bind(&MyCltSession1::read_handler, shared_from_this(), boost::asio::placeholders::error, str));
}

void MMyLib::MyCltSession1::read_handler(const boost::system::error_code& ec, boost::shared_ptr<vector<char> > str)
{
	if(ec)
		return;
	LOG_INFO<< &(*str)[0]<< endl<< endl;
}

//MyClient
MMyLib::MyClient::MyClient(io_service& in_oIos): m_oIos(in_oIos), m_oEp(ip::address::from_string(CLTIP), CLTPORT)
{
	start();
}

MMyLib::MyClient::~MyClient()
{}

void MMyLib::MyClient::start()
{
	boost::shared_ptr<MMyLib::MyCltSession1> new_session = boost::make_shared<MMyLib::MyCltSession1>(m_oIos);
	new_session->m_oSocket->async_connect(m_oEp, boost::bind(&MyClient::conn_handler, this, new_session, boost::asio::placeholders::error));
}

void MMyLib::MyClient::conn_handler(boost::shared_ptr<MyCltSession1> new_session, const boost::system::error_code& ec)
{
	if(ec)
		return;
	new_session->start();
}

