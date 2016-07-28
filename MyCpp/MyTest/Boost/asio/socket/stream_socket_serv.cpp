#include <boost/asio.hpp>
#include <iostream>
#include <unistd.h>
using namespace boost;
using namespace boost::asio;
using namespace std;

int main()
{
	io_service ios;

	ip::tcp::endpoint ep(ip::tcp::v4(), 54321);
	ip::tcp::acceptor acceptor(ios, ep);

	while(true)
	{
		ip::tcp::iostream tcp_stream;
		acceptor.accept(*tcp_stream.rdbuf());
		tcp_stream<< "hello tcp stream";
	}
	return 0;
}