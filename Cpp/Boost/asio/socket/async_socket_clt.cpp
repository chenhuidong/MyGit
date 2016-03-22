#include <boost/asio.hpp>
#include <boost/bind.hpp>
#include <iostream>
using namespace boost;
using namespace boost::asio;
using namespace std;

class client
{
private:
	io_service& ios;
	ip::tcp::endpoint ep;
	typedef shared_ptr<ip::tcp::socket> sock_pt;
public:
	client(io_service& io): ios(io), ep(ip::address::from_string("127.0.0.1"), 54321)
	{
		start();
	}

	void start()
	{
		sock_pt sock(new ip::tcp::socket(ios));
		sock->async_connect(ep, boost::bind(&client::conn_handler, this, boost::asio::placeholders::error, sock));
	}

	void conn_handler(const system::error_code& ec, sock_pt sock)
	{
		if(ec)
			return;

		cout<< "recive from "<< sock->remote_endpoint().address();
		shared_ptr<vector<char> > str(new vector<char>(100, 0));

		sock->async_read_some(buffer(*str), boost::bind(&client::read_handler, this, boost::asio::placeholders::error, str));

		start();
	}

	void read_handler(const system::error_code& ec, shared_ptr<vector<char> > str)
	{
		if(ec)
			return;

		cout<< &(*str)[0]<< endl;
	}
};


int main()
{
	try
	{
		cout<< "client start."<< endl;
		io_service ios;
		client cl(ios);
		ios.run();
	}
	catch(std::exception& e)
	{
		cout<< e.what()<< endl;
	}
	return 0;
}
