#include "MyStdAfx.h"
#include "MyLog.h"
using namespace MMyLib;

extern int InitLog(const char * in_sFileName = NULL);
extern int UninitLog();

int main(int argc, char* argv[])
{
	std::string initFileName = "MyLog.properties";

	InitLog(initFileName.c_str());
	LOG_WARN("Storm is coming");
	LOG_INFO("Ready for storm.");
	UninitLog();
	return 0;
}