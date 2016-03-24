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

	boost::thread t1(printing, ref(x), "hello");
	boost::thread t2(printing, ref(x), "boost");
	//boost::this_thread::sleep_for(boost::chrono::seconds(2));
	
	t1.timed_join(boost::posix_time::seconds(1));
	t2.join();
	return 0;
}

//g++ iostream_print.cpp -oiostream_print -lboost_system -lboost_thread-mt
