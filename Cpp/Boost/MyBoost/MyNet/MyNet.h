#ifndef __MY_LIB_MY_NET_H_
#define __MY_LIB_MY_NET_H_

#include "MyStdAfx.h"
#include <boost/asio.hpp>
#include <boost/bind.hpp>
using namespace boost;
using namespace boost::asio;

namespace MMyLib
{
typedef std::shared_ptr<ip::tcp::socket> sock_pt;

class MySessionBase
{
public:
	MySessionBase(boost::asio::io_service& ios);
	virtual ~MySessionBase();
public:
    sock_pt sock;
};

class MyServSessionBase: public MySessionBase
{
public:
	MyServSessionBase(boost::asio::io_service& ios);
	virtual ~MyServSessionBase();

	virtual void start() = 0;
	virtual void write_handler(const boost::system::error_code& ec) = 0;
	virtual void read_handler(const boost::system::error_code& ec, std::shared_ptr<vector<char> > str) = 0;
};

class MyServSession1: public MyServSessionBase
{
public:
	MyServSession1(boost::asio::io_service& io_service);
	virtual ~MyServSession1();

	void start();
	void write_handler(const boost::system::error_code& ec);
	void read_handler(const boost::system::error_code& ec, std::shared_ptr<vector<char> > str);
};

class MyServer
{
public:
	MyServer(io_service& io);
	void start();
	void accept_handler(MyServSession1* new_session, const boost::system::error_code& ec);
private:
	boost::asio::io_service& ios;
  	ip::tcp::acceptor acceptor;
};
};

#endif