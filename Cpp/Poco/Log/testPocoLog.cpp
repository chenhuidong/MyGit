#include "../../stdafx.h"

#define __POCO_LOG_
#include "../../MyLog.h"


int main(int argc, char* argv[]) 
{
    // Initialize Google's logging library.
    CMyLog mylog;
	mylog.INITIALIZE(argv[0]);
	
	//LOG_INFO("This is a warning %d.", 1);
	GetLogger->information("This is a warning %d", 1);
	mylog.UNINITIALIZE();
}