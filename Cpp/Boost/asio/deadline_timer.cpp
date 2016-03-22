#include <boost/asio.hpp>
#include <boost/date_time/posix_time/posix_time.hpp>
#include <iostream>
using namespace boost;
using namespace std;

int main()
{
	io_service ios;

	deadline_timer t(ios, boost::posix_time::seconds(2));
	cout<< t.expires_at()<< endl;

	t.wait();
	cout<< "hello asio"<< endl;
	return 0;
}
