#include <boost/asio.hpp>
#include <iostream>
#include <unistd.h>
using namespace boost;
using namespace boost::asio;
using namespace std;

int main()
{
	cout<< "client start."<< endl;
	io_service ios;

	ip::udp::endpoint send_ep(ip::address::from_string("127.0.0.1"), 54321);
	
	ip::udp::socket sock(ios);
	sock.open(ip::udp::v4());

	char buf[1];
	sock.send_to(buffer(buf), send_ep);

	std::vector<char> v(100, 0);
	ip::udp::endpoint recv_ep;
	sock.receive_from(buffer(v), recv_ep);
	cout<< "recv from "<< recv_ep.address()<< " ";
	cout<< &v[0]<< endl;
	return 0;
}