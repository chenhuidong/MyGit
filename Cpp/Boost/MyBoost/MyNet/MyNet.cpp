#include "MyNet.h"

MyServSession1::MyServSession1(boost::asio::io_service& ios): sock(new ip::tcp::socket(ios))
{

}

MyServSession1::~MyServSession1()
{
}

void MyServSession1::start()
{
	
}

void MyServSession1::write_handler(const boost::system::error_code&)
{

}

void MyServSession1::read_handler(const system::error_code& ec, std::shared_ptr<vector<char> > str)
{

}
