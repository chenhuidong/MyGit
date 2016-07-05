#include "MyNet.h"

/*
class MyServer
{
private:
	io_service &ios;
	ip::tcp::acceptor acceptor;
	typedef std::shared_ptr<ip::tcp::socket> sock_pt;
public:
	MyServer(io_service& io): ios(io), acceptor(ios, ip::tcp::endpoint(ip::tcp::v4(), 54321))
	{
		start();
	}

	void start()
	{
		sock_pt sock(new ip::tcp::socket(ios));
		acceptor.async_accept(*sock, boost::bind(&MyServer::accept_handler, this, boost::asio::placeholders::error, sock));		
	}

	void accept_handler(const boost::system::error_code& ec, sock_pt sock)
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

	void write_handler(const boost::system::error_code&)
	{
		cout<< "send msg complete."<< endl;
	}
};
*/

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