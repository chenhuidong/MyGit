#include <boost/thread/thread.hpp>
#include <boost/thread/mutex.hpp>  
#include <boost/thread/once.hpp>
#include <iostream>
using namespace boost;
using namespace std;

void to_interrupt(boost::atom_int& x, const string& str)
{
	try
	{
		for(int i=0; i<5; ++i)
		{
			boost::this_thread::sleep(boost::posix_time::seconds(1));
			mutex::scoped_lock lock(io_mu);
			cout<< str<< ++x<< endl;
		}
	}
	catch(boost::thread_interrupted&)
	{
		cout<< "thread_interrupted"<< endl;
	}
}

int main()
{
	atom_int x;
	thread t(to_interrupt, ref(x), "hello");
	boost::this_thread::sleep(boost::posix_time::seconds(2));
	t.to_interrupt();
	t.join();
}