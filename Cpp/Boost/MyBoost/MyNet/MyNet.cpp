#include "MyNet.h"

//MyServer
MMyLib::MyServer::MyServer(io_service& io): ios(io), acceptor(ios, ip::tcp::endpoint(ip::tcp::v4(), SERVPORT))
{
	start();
}

void MMyLib::MyServer::start()
{
	//sock_pt sock(new ip::tcp::socket(ios));
	session* new_session = new session(io_service_);
	acceptor.async_accept(*sock, boost::bind(&MyServer::accept_handler, this, boost::asio::placeholders::error, sock));		
}

void MMyLib::MyServer::accept_handler(const boost::system::error_code& ec, sock_pt sock)
{
	/*
	if(ec)
		return ;
	cout<< "MyClients:";
	cout<< sock->remote_endpoint().address()<< endl;
	sock->async_write_some(buffer("hello asio"), \
		boost::bind(&MyServer::write_handler, this, boost::asio::placeholders::error));
	*/
    if (!ec)
    {
      new_session->start();
    }
    else
    {
      delete new_session;
    }
	start();
}

void MMyLib::MyServer::write_handler(const boost::system::error_code&)
{
	cout<< "send msg complete."<< endl;
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
	cout<< "recive from "<< sock->remote_endpoint().address()<< endl;
	std::shared_ptr<vector<char> > str(new vector<char>(100, 0));

	sock->async_read_some(buffer(*str), boost::bind(&MyClient::read_handler, this, boost::asio::placeholders::error, str));
}

void MMyLib::MyClient::read_handler(const system::error_code& ec, std::shared_ptr<vector<char> > str)
{
	if(ec)
		return;
	cout<< &(*str)[0]<< endl<< endl;
}
