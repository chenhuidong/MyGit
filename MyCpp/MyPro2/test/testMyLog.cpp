#include "MyStdAfx.h"
#include "MyLog.h"
using namespace MMyLib;

int main(int argc, char* argv[])
{	
	
	std::string initFileName = "MyLog.properties";

	InitLog(initFileName.c_str());
	if(pLog)
		cout<< "1"<< endl;
	else
		cout<< "2"<< endl;
	//LOG_WARN("Storm is coming");
	LOG_INFO("Ready for storm.");
	UninitLog();
	return 0;
}