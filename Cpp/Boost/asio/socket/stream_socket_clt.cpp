#include <boost/asio.hpp>
#include <iostream>
#include <unistd.h>
using namespace boost;
using namespace boost::asio;
using namespace std;

int main()
{
	//for(int i=0; i<5; ++i)
	{
		ip::tcp::iostream tcp_stream("127.0.0.1", "54321");
		string str;
		getline(tcp_stream, str);
		cout<< str<< endl;
	}
	return 0;
}