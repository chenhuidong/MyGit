#include "MyStdAfx.h"
#include "MyLog.h"
using namespace MMyLib;

int main(int argc, char* argv[])
{
	std::string initFileName = "MyLog.properties";

	Initialize(initFileName.c_str());
	LOG_WARN("Storm is coming");
	LOG_INFO("Ready for storm.");
	Uninitialize();
	return 0;
}