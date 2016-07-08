#ifndef __MY_LIB_MY_NET_H_
#define __MY_LIB_MY_NET_H_

#include "MyStdAfx.h"
#include <boost/asio.hpp>
#include <boost/bind.hpp>
using namespace boost;
using namespace boost::asio;
using namespace std::shared_ptr;

namespace MMyLib
{
class MyServer
{
private:
	io_service &ios;
	ip::tcp::acceptor acceptor;
	typedef shared_ptr<ip::tcp::socket> sock_pt;
public:
	MyServer(io_service& io);
	void start();
	void accept_handler(const boost::system::error_code& ec, sock_pt sock);
	void write_handler(const boost::system::error_code&);
};

class MyClient
{
private:
	io_service& ios;
	ip::tcp::endpoint ep;
	typedef shared_ptr<ip::tcp::socket> sock_pt;
public:
	MyClient(io_service& io);
	void start();
	void conn_handler(const system::error_code& ec, sock_pt sock);
	void read_handler(const system::error_code& ec, shared_ptr<vector<char> > str);
};

};

#endif