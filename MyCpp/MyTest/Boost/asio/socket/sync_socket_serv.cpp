#include <boost/asio.hpp>
#include <iostream>
using namespace boost;
using namespace boost::asio;
using namespace std;

int main()
{
	try
	{
		cout<< "server start."<< endl;
		io_service ios;
		ip::tcp::acceptor acceptor(ios, ip::tcp::endpoint(ip::tcp::v4(), 54321));
		cout<< acceptor.local_endpoint().address() <<endl;

		while(true) 
		{
			ip::tcp::socket sock(ios);
			acceptor.accept(sock);

			cout<< "client:";
			cout<< sock.remote_endpoint().address()<< endl;

			sock.write_some(buffer("hello asio"));  
		}
	}
	catch(std::exception& e)
	{
		cout<< e.what()<< endl;
	}
	return 0;
}