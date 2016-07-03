#ifndef __MY_LIB_MY_NET_H_
#define __MY_LIB_MY_NET_H_

#include "MyStdAfx.h"
#include <boost/asio.hpp>
#include <boost/bind.hpp>
using namespace boost;
using namespace boost::asio;

namespace MMyLib{
class server
{
private:
	io_service &ios;
	ip::tcp::acceptor acceptor;
	typedef MMyLib::shared_ptr<ip::tcp::socket> sock_pt;
public:
	server(io_service& io): ios(io), acceptor(ios, ip::tcp::endpoint(ip::tcp::v4(), 54322))
	{
		start();
	}

	void start()
	{
		sock_pt sock(new ip::tcp::socket(ios));
		acceptor.async_accept(*sock, boost::bind(&server::accept_handler, this, boost::asio::placeholders::error, sock));		
	}

	void accept_handler(const boost::system::error_code& ec, sock_pt sock)
	{
		if(ec)
			return ;
		cout<< "clients:";
		cout<< sock->remote_endpoint().address()<< endl;
		sleep(20);
		sock->async_write_some(buffer("hello asio"), \
			boost::bind(&server::write_handler, this, boost::asio::placeholders::error));

		start();
	}

	void write_handler(const boost::system::error_code&)
	{
		cout<< "send msg complete."<< endl;
	}
};
};

#endif