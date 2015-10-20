#include "Poco/Thread.h"
#include "Poco/Runnable.h"
#include <iostream>

void run(void *name)
{
	std::cout << "Hello, world!"<< (char*)name << std::endl;
}


int main(int argc, char** argv)
{
	Poco::Thread thread;
	thread.start(run, "fdsfds");
	thread.join();
	return 0;
}