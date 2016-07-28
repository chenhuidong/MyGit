#include <boost/asio.hpp>
#include <boost/date_time/posix_time/posix_time.hpp>
#include <iostream>
using namespace boost;
using namespace boost::asio;
using namespace std;

void print(const boost::system::error_code&)
{
	cout<< "hello asio"<< endl;
}

int main()
{
	io_service ios;

	deadline_timer t(ios, boost::posix_time::seconds(2));
	t.async_wait(print);

	cout<< "it show before expired"<< endl;
	
	ios.run();
	return 0;
}