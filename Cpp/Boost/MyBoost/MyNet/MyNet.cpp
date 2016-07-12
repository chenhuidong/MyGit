#include "MyNet.h"

MMyLib::MySessionBase::MySessionBase(boost::asio::io_service& ios): sock(new ip::tcp::socket(ios))
{}

MMyLib::MySessionBase::~MySessionBase()
{}

MMyLib::MySessionBase::MyServSessionBase(boost::asio::io_service& ios): MySessionBase(ios)
{}

MMyLib::MySessionBase::~MyServSessionBase()
{}

MMyLib::MyServSession1::MyServSession1(boost::asio::io_service& ios): MyServSessionBase(ios)
{}

MMyLib::MyServSession1::~MyServSession1()
{
}

void MMyLib::MyServSession1::start()
{
}

void MMyLib::MyServSession1::write_handler(const boost::system::error_code&)
{
}

void MMyLib::MyServSession1::read_handler(const system::error_code& ec, std::shared_ptr<vector<char> > str)
{
}
