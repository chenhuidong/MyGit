#include "MyNet.h"
#include "MyLog.h"
using namespace MMyLib;

int main(int argc, char** argv)
{
	try
	{
		std::string initFileName = "MyLog.properties";
		InitLog(initFileName.c_str());
		LOG_INFO("server start.");
		io_service ios;

		MMyLib::MyServer serv(ios);
		ios.run();
		UninitLog();
	}
	catch(std::exception& e)
	{
		cout<< e.what()<< endl;
		UninitLog();
	}
	return 0;
}