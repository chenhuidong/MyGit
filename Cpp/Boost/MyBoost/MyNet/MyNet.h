#ifndef __MY_LIB_MY_NET_H_
#define __MY_LIB_MY_NET_H_

#include "MyStdAfx.h"
#include <boost/asio.hpp>
#include <boost/bind.hpp>
using namespace boost;
using namespace boost::asio;

namespace MMyLib
{
class session
{
public:
  session(boost::asio::io_service& io_service)
    : socket_(io_service)
  {
  }

  tcp::socket& socket()
  {
    return socket_;
  }

  void start()
  {
    socket_.async_read_some(boost::asio::buffer(data_, max_length),
        boost::bind(&session::handle_read, this,
          boost::asio::placeholders::error,
          boost::asio::placeholders::bytes_transferred));
  }

private:
  void handle_read(const boost::system::error_code& error,
      size_t bytes_transferred)
  {
    if (!error)
    {
      boost::asio::async_write(socket_,
          boost::asio::buffer(data_, bytes_transferred),
          boost::bind(&session::handle_write, this,
            boost::asio::placeholders::error));
    }
    else
    {
      delete this;
    }
  }

  void handle_write(const boost::system::error_code& error)
  {
    if (!error)
    {
      socket_.async_read_some(boost::asio::buffer(data_, max_length),
          boost::bind(&session::handle_read, this,
            boost::asio::placeholders::error,
            boost::asio::placeholders::bytes_transferred));
    }
    else
    {
      delete this;
    }
  }

  tcp::socket socket_;
  enum { max_length = 1024 };
  char data_[max_length];
};

class MyServer
{
private:
	io_service &ios;
	ip::tcp::acceptor acceptor;
	typedef std::shared_ptr<ip::tcp::socket> sock_pt;
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
	typedef std::shared_ptr<ip::tcp::socket> sock_pt;
public:
	MyClient(io_service& io);
	void start();
	void conn_handler(const system::error_code& ec, sock_pt sock);
	void read_handler(const system::error_code& ec, std::shared_ptr<vector<char> > str);
};

};

#endif