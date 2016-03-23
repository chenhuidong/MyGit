#include <boost/thread/thread.hpp>
#include <boost/thread/mutex.hpp>  
#include <iostream>
using namespace boost;
using namespace std;

boost::mutex io_mu;

void printing(atomix_int& x, const string& str)
{
	for(int i=0; i<5; ++i)
	{
		mutex::scoped_lock lock(io_mu);
		cout<< str<< ++x<< endl;
	}
}

int main()
{
	atomic_int x;

	thread(printing, ref(x), "hello");
	thread(printing, ref(x), "boost");
	this_thread::sleep_for(chrono::seconds(2));
	return 0;
}
