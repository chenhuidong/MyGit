#include "../../stdafx.h"

#define __POCO_LOG_
#include "../../MyLog.h"


int main(int argc, char* argv[]) 
{
    // Initialize Google's logging library.
	INITIALIZE_LOG(argv[0]);
	
	//LOG_INFO("This is a warning %d", 1);
	poco_information_f2("This is a warning %d", 1);
	UNINITIALIZE_LOG();
}