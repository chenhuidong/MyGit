#ifndef __MY_LIB_MY_NET_H_
#define __MY_LIB_MY_NET_H_

#include "MyStdAfx.h"
#include "MyLog.h"
#include "MyTR.h"
#include <boost/asio.hpp>
#include <boost/bind.hpp>
using namespace boost;
using namespace boost::asio;

//#include "student.pb.h"

namespace MMyLib
{
typedef boost::shared_ptr<ip::tcp::socket> sock_pt;

class MySessionBase
{
public:
	MySessionBase(boost::asio::io_service& ios);
	virtual ~MySessionBase();

	virtual void start() = 0;
	virtual void write_handler(const boost::system::error_code& ec) = 0;
	virtual void read_handler(const boost::system::error_code& ec, boost::shared_ptr<vector<char> > str) = 0;
public:
    sock_pt m_oSocket;
};

class MyServSession1: public MySessionBase, public boost::enable_shared_from_this<MyServSession1>
{
public:
	MyServSession1(boost::asio::io_service& io_service);
	virtual ~MyServSession1();

	void start();
	void write_handler(const boost::system::error_code& ec);
	void read_handler(const boost::system::error_code& ec, boost::shared_ptr<vector<char> > str);
};


class MyCltSession1: public MySessionBase, public boost::enable_shared_from_this<MyCltSession1>
{
public:
	MyCltSession1(boost::asio::io_service& io_service);
	virtual ~MyCltSession1();

	void start();
	void write_handler(const boost::system::error_code& ec);
	void read_handler(const boost::system::error_code& ec, boost::shared_ptr<vector<char> > str);
};

class MyServer
{
public:
	MyServer(io_service& in_oIos);
	virtual ~MyServer();

	void start();
	template <typename T>
	void accept_handler(boost::shared_ptr<T> new_session, const boost::system::error_code& ec)
	{
		if (ec)
			return;
	    new_session->start();
	    start();		
	}
private:
	boost::asio::io_service& m_oIos;
  	ip::tcp::acceptor m_oAcceptor;
};

class MyClient
{
public:
	MyClient(io_service& in_oIos);
	virtual ~MyClient();
	void start();
	void conn_handler(boost::shared_ptr<MyCltSession1> new_session, const boost::system::error_code& ec);
private:
	boost::asio::io_service& m_oIos;
	ip::tcp::endpoint m_oEp;
};

};
#endif