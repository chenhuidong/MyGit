#include <boost/asio.hpp>
#include <boost/date_time/posix_time/posix_time.hpp>
#include <boost/function.hpp>
#include <boost/bind.hpp>
#include <iostream>
using namespace boost;
using namespace boost::asio;
using namespace std;


class a_timer
{
private:
	int count, count_max;
	function<void()> f;
	deadline_timer t;
public:
	template<typename F>
	a_timer(io_service& ios, int x, F func):f(func), count_max(x), count(0),\
	t(ios, boost::posix_time::millisec(500))
	{
		t.async_wait(boost::bind(&a_timer::call_func, this, boost::asio::placeholders::error));
	}

	void call_func(const boost::system::error_code&)
	{
		if(count >= count_max)
			return;
		++count;
		f();
		t.expires_at(t.expires_at() + boost::posix_time::millisec(500));
		t.async_wait(boost::bind(&a_timer::call_func, this, boost::asio::placeholders::error));
	}
};


void client(io_service &ios)
{
	try
	{
		cout<< "client start."<< endl;
		ip::tcp::socket sock(ios);
		ip::tcp::endpoint ep(ip::address::from_string("127.0.0.1"), 54321);

		sock.connect(ep);

		std::vector<char> str(100, 0);
		sock.read_some(buffer(str));
		cout<< "recive from "<< sock.remote_endpoint().address();
		cout<< &str[0]<< endl;
	}
	catch(std::exception& e)
	{
		cout<< e.what()<< endl;
	}
}

int main()
{
	io_service ios;
	a_timer at(ios, 5, bind(client, ref(ios)));
	ios.run();
	return 0;
}