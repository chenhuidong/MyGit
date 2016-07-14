#ifndef __MY_LIB_MY_NET_H_
#define __MY_LIB_MY_NET_H_

#include "MyStdAfx.h"
#include "MyTR.h"
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
    sock_pt m_oSocket;
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

class MyServSession1: public MyServSessionBase, public boost::enable_shared_from_this<MyServSession1>
{
public:
	MyServSession1(boost::asio::io_service& io_service);
	virtual ~MyServSession1();

	void start();
	void write_handler(const boost::system::error_code& ec);
	void read_handler(const boost::system::error_code& ec, std::shared_ptr<vector<char> > str);
};

/*
class MyCltSession1: public MyServSessionBase
{
public:
	MyCltSession1(boost::asio::io_service& io_service);
	virtual ~MyCltSession1();

	void start();
	void write_handler(const boost::system::error_code& ec);
	void read_handler(const boost::system::error_code& ec, std::shared_ptr<vector<char> > str);
};
*/

class MyServer
{
public:
	MyServer(io_service& in_oIos);
	void start();
	void accept_handler(std::shared_ptr<MyServSession1> new_session, const boost::system::error_code& ec);
private:
	boost::asio::io_service& m_oIos;
  	ip::tcp::acceptor m_oAcceptor;
};











class MyClient
{
private:
	io_service& ios;
	ip::tcp::endpoint ep;
	typedef std::shared_ptr<ip::tcp::socket> sock_pt;
public:
	MyClient(io_service& io);
	void start();
	void conn_handler(const system::error_code& ec, sock_pt sock);
	void write_handler(const boost::system::error_code& ec, sock_pt sock);
	void read_handler(const system::error_code& ec, std::shared_ptr<vector<char> > str);
};


};
#endif