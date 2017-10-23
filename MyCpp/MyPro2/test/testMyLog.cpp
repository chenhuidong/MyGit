#include "MyStdAfx.h"
#include "MyLog.h"

int main(int argc, char* argv[])
{
	std::string initFileName = "MyLog.properties";

	MyLog::Initialize(initFileName);
	MyLog::pLog.warn("Storm is coming");
	MyLog::pLog.info("Ready for storm.");
	MyLog::Uninitialize();
	return 0;
}