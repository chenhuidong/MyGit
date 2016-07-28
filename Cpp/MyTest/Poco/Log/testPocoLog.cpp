#include "../../stdafx.h"

#define __POCO_LOG_
#include "../../MyLog.h"


int main(int argc, char* argv[]) 
{
    // Initialize Google's logging library.
    CMyLog mylog;
	mylog.INITIALIZE();
	
	//LOG_INFO("This is a warning %d.", 1);
	mylog.GetLogger()->information("This is a warning %d", 1);
	mylog.UNINITIALIZE();
}