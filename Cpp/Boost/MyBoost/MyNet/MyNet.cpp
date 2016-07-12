#include "MyNet.h"

MMyLib::MySessionBase::MySessionBase(boost::asio::io_service& ios): sock(new ip::tcp::socket(ios))
{}

MMyLib::MySessionBase::~MySessionBase()
{}

MMyLib::MyServSessionBase::MyServSessionBase(boost::asio::io_service& ios): MySessionBase(ios)
{}

MMyLib::MyServSessionBase::~MyServSessionBase()
{}

MMyLib::MyServSession1::MyServSession1(boost::asio::io_service& ios): MyServSessionBase(ios)
{}

MMyLib::MyServSession1::~MyServSession1()
{}

void MMyLib::MyServSession1::start()
{
	//cout<< "recive from "<< sock->remote_endpoint().address()<< endl;
	std::shared_ptr<vector<char> > str(new vector<char>(100, 0));
	sock->async_read_some(buffer(*str), boost::bind(&MyServSession1::read_handler, this, boost::asio::placeholders::error, str));
}

void MMyLib::MyServSession1::write_handler(const boost::system::error_code& ec)
{
	if (ec)
		return;
	std::shared_ptr<vector<char> > str(new vector<char>(100, 0));
	sock->async_read_some(buffer(*str), boost::bind(&MyServSession1::read_handler, this, boost::asio::placeholders::error, str));
}

void MMyLib::MyServSession1::read_handler(const boost::system::error_code& ec, std::shared_ptr<vector<char> > str)
{
	if (ec)
		return;
	cout<< &(*str)[0]<< endl;
	sock->async_write_some(buffer("hello asio"), boost::bind(&MyServSession1::write_handler, this, boost::asio::placeholders::error));
}
