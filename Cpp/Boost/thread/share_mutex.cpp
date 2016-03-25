#include <boost/thread/thread.hpp>
#include <boost/thread/mutex.hpp>  
#include <boost/thread/once.hpp>
#include <iostream>
using namespace boost;
using std::cout;
using std::endl;

class rw_data
{
private:
	int m_x;
	shared_mutex rw_mu;
public:
	rw_data():m_x(0){}
	void write()
	{
		unique_lock<shared_mutex> ul(rw_mu);
		++m_x;
	}
	void read(int *x)
	{
		shared_lock<shared_mutex> sl(rw_mu);
		*x = m_x;
	}
};

void writer(rw_data &d)
{
	for(int i=0; i<20; ++i)
	{
		this_thread::sleep(posix_time::millisec(10));
		d.write();
	}
}

void reader(rw_data &d)
{
	int x;
	for(int i=0; i<10; ++i)
	{
		this_thread::sleep(posix_time::millisec(5));
		d.read(&x);
		mutex::scoped_lock lock(io_mu);
		cout<< "reader:"<< x<< endl;
	}
}

int main()
{
	rw_data d;
	thread_group pool;
	pool.create_thread(bind(reader, ref(d)));
	pool.create_thread(bind(reader, ref(d)));
	pool.create_thread(bind(reader, ref(d)));
	pool.create_thread(bind(writer, ref(d)));
	pool.create_thread(bind(writer, ref(d)));
	pool.join_all();
}