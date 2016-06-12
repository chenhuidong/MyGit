#include "MyThread.h"
using namespace MMyLib;

void my_func()
{
	std::cout<<"thread test."<<endl;
}

int main()
{
	MyThread t_oMyThread(my_func);
	boost::this_thread::sleep(boost::posix_time::seconds(2));
	return 0;
}