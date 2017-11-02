#include "MyThread.h"
using namespace MMyLib;

void my_func(int x, int y)
{
	std::cout<< "thread test. "<< x<< " "<< y<< endl;
}

int main()
{
	int x = 5, k = 4;
	IMyThread t_oMyThread(boost::bind(my_func, boost::ref(x), boost::ref(k)));
	//boost::this_thread::sleep(boost::posix_time::seconds(2));
	t_oMyThread.Join();
	return 0;
}