#include <boost/thread/thread.hpp>
#include <boost/thread/mutex.hpp>  
#include <boost/thread/once.hpp>
#include <iostream>
using namespace boost;
using namespace std;

boost::mutex io_mu;

template<typename T> 
class basic_atom: noncopyable 
{ 
private: 
T n; 
mutex mu; 
public: 
basic_atom(T x = T()) :n(x) {} 
T operator++() { 
mutex::scoped_lock lock(mu); 
return ++n; 
} 
operator T() { return n; } 
}; 

typedef basic_atom<int> atom_int; 

void to_interrupt(atom_int& x, const string& str)
{
	try
	{
		for(int i=0; i<5; ++i)
		{
			//boost::this_thread::sleep(boost::posix_time::seconds(1));
			mutex::scoped_lock lock(io_mu);
			cout<< str<< ++x<< endl;
			boost::this_thread::interruption_point();
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
	t.interrupt();
	t.join();
}