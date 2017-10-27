#include "MyStdAfx.h"
#include "MyLog.h"
using namespace MMyLib;

int main(int argc, char* argv[])
{
	std::string initFileName = "MyLog.properties";

	MyLog::Initialize(initFileName);
	LOG_WARN("Storm is coming");
	LOG_INFO("Ready for storm.");
	MyLog::Uninitialize();
	return 0;
}