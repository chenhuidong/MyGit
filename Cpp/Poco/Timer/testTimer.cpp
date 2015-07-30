#include "Poco/Timer.h"
#include "Poco/Thread.h"
#include <iostream>
using Poco::Timer;
using Poco::TimerCallback;

class TimerExample
{
	public:
	void onTimer(Poco::Timer& timer)
	{
		std::cout << "onTimer called." << std::endl;
	}
};

int main(int argc, char** argv)
{
	TimerExample te;
	Timer timer(250, 500); // fire after 250ms, repeat every 500ms
	timer.start(TimerCallback<TimerExample>(te, &TimerExample::onTimer));
	Poco::Thread::sleep(5000);
	timer.stop();
	return 0;
}

//g++ testTimer.cpp -omain -lPocoFoundation