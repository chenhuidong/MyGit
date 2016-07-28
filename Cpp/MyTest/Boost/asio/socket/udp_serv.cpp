#include <boost/asio.hpp>
#include <iostream>
#include <unistd.h>
using namespace boost;
using namespace boost::asio;
using namespace std;

int main()
{
	cout<< "udp server start."<< endl;
	io_service ios;
	
	ip::udp::socket sock(ios, ip::udp::endpoint(ip::udp::v4(), 54321));

	for(;;)
	{
		char buf[1];
		ip::udp::endpoint ep;

		boost::system::error_code ec;
		sock.receive_from(buffer(buf), ep, 0, ec);

		if(ec && ec!=error::message_size)
			throw boost::system::system_error(ec);

		cout<< "send to "<< ep.address()<< endl;
		sock.send_to(buffer("hello asio udp"), ep); 
	}
	return 0;
}