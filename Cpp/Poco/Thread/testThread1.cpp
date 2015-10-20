#include "Poco/Thread.h"
#include "Poco/Runnable.h"
#include <iostream>

class test
{
public:
	static void run(void *name)
	{
		std::cout << "Hello, world!"<< (char*)name << std::endl;
	}
};

int main(int argc, char** argv)
{
	Poco::Thread thread;
	thread.start(test::run, (void *)"fdsfds");
	thread.join();
	return 0;
}