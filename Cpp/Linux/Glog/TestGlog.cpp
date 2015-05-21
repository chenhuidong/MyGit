#include "../../stdafx.h"

int main(int argc, char* argv[]) {
     // Initialize Google's logging library.
	/*
	FLAGS_logtostderr = 0;
	string t_strWorkPath = getenv("WORKPATH");
	cout<<t_strWorkPath<<endl;
	FLAGS_log_dir = t_strWorkPath + "/Log";
	google::InitGoogleLogging(argv[0]);
	*/

	INITIALIZE_LOG();
	LOG_INFO << "Hello, Glog!";
	LOG_ERROR << "Hello, Glog!";
}