#include "Poco/Thread.h"
#include "Poco/Runnable.h"
#include <iostream>

void run(void *)
{
	std::cout << "Hello, world!" << std::endl;
}


int main(int argc, char** argv)
{
	Poco::Thread thread;
	thread.start(run);
	thread.join();
	return 0;
}