#include "../../stdafx.h"
#include "../../MyLog.h"


int main(int argc, char* argv[]) 
{
    // Initialize Google's logging library.
    #define FLAGS_INFO
	INITIALIZE_LOG(argv[0]);
	
	LOG_INFO << "Hello1, Glog!";
	LOG_ERROR << "Hello2, Glog!";
	//LOG_FATAL << "Hello3, Glog!";
}