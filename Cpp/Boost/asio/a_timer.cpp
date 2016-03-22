#include <boost/asio.hpp>
#include <boost/date_time/posix_time/posix_time.hpp>
#include <boost/function.hpp>
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

void print1()
{
	cout<< "hello asio"<< endl;
}

void print2()
{
	cout<< "hello boost"<< endl;
}

int main()
{
	io_service ios;
	a_timer at1(ios, 5, print1);
	a_timer at2(ios, 5, print2);
	ios.run();
	return 0;
}