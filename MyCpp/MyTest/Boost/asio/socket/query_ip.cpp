#include <boost/lexical_cast.hpp>
#include <boost/asio.hpp>
#include <iostream>
using namespace boost;
using namespace boost::asio;
using namespace std;

void resolve_connect(ip::tcp::socket &sock, const char* name, int port)
{
	ip::tcp::resolver rlv(sock.get_io_service());
	ip::tcp::resolver::query qry(name, lexical_cast<string> (port));

	ip::tcp::resolver::iterator iter = rlv.resolve(qry);
	ip::tcp::resolver::iterator end;
	system::error_code ec = error::host_not_found;

	for(; ec && iter!=end; ++iter)
	{
		sock.close();
		sock.connect(*iter, ec);
	}	
	if(ec)
	{
		cout<< "can not connect."<< endl;
		throw system::system_error(ec);
	}
	cout<< sock.remote_endpoint().address()<< endl;
	cout<< "connect success."<< endl;
}

int main()
{
	try
	{
		io_service ios;
		ip::tcp::socket sock(ios);
		resolve_connect(sock, "www.baidu.com", 80);
		ios.run();
	}
	catch(std::exception& e)
	{
		cout<< e.what()<< endl;
	}
}