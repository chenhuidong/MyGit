#include "MyThread.h"
using namespace MMyLib;

void my_func(int i)
{
	std::cout<< "thread test. "<< i<< endl;
}

int main()
{
	int i = 5;
	MyThread t_oMyThread(boost::bind(my_func, ref(i)));
	//boost::this_thread::sleep(boost::posix_time::seconds(2));
	t_oMyThread.Join();
	return 0;
}