#include <boost/thread/thread.hpp>
#include <boost/thread/mutex.hpp>  
#include <boost/thread/once.hpp>
#include <iostream>
using namespace boost;
using namespace std;

boost::mutex io_mu;

void printing(boost::atomic_int& x, const string& str)
{
	for(int i=0; i<5; ++i)
	{
		mutex::scoped_lock lock(io_mu);
		cout<< str<< ++x<< endl;
	}
}

int main()
{
	boost::atomic_int x;

	boost::thread(printing, ref(x), "hello");
	boost::thread(printing, ref(x), "boost");
	boost::this_thread::sleep_for(chrono::seconds(2));
	return 0;
}
