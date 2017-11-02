#include "MyNet.h"
using namespace MMyLib;

int main(int argc, char** argv)
{
	try
	{
		std::string initFileName = "MyLog.properties";
		InitLog(initFileName.c_str());
		LOG_INFO<< "client start."<< endl;
		io_service ios;
		
		MMyLib::MyClient cl(ios);
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