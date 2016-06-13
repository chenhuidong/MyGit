#define FLAGS_INFO
#include "MyLog.h"


int main(int argc, char* argv[]) 
{
	cout<< "1"<< endl;
    // Initialize Google's logging library.
	MMyLib::INITIALIZE_LOG(argv[0]);
	
	cout<< "2"<< endl;
	LOG_INFO << "Hello1, Glog!";
	LOG_ERROR << "Hello2, Glog!";
	//LOG_FATAL << "Hello3, Glog!";
	cout<< "3"<< endl;
	return 0;
}