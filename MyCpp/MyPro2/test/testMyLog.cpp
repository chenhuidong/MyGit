#include "MyStdAfx.h"
#include "MyLog.h"
using namespace MMyLib;

int main(int argc, char* argv[])
{	
	
	const char* initFileName = "MyLog.properties";

	InitLog(initFileName);
	//LOG_WARN("Storm is coming");
	LOG_INFO("Ready for storm.");
	UninitLog();
	
	pLog = NULL;
	return 0;
}