#include "../../stdafx.h"

#define __POCO_LOG_
#include "../../MyLog.h"


int main(int argc, char* argv[]) 
{
    // Initialize Google's logging library.
	INITIALIZE_LOG(argv[0]);
	
	LOG_INFO("This is a warning");
	UNINITIALIZE_LOG();
}