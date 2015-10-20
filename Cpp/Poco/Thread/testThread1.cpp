#include "Poco/Thread.h"
#include "Poco/Runnable.h"
#include <iostream>
#include <string>
using namespace std;

class Test
{
public:
	Test():name("chenhuidong"){}
	static void run(void *_this)
	{
		std::cout << "Hello, world!"<< _this->name << std::endl;
	}
	string name;
};

int main(int argc, char** argv)
{
	Poco::Thread thread;
	Test test;
	thread.start(Test::run, (void *)(&test));
	thread.join();
	return 0;
}