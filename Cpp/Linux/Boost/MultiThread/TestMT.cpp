#include <boost/thread.hpp>
#include "../../../stdafx.h"

void my_func()
{
	cout<<"thread test."<<endl;
}

int main()
{
	boost::thread t(my_func);
	t.join();
	return 0;
}