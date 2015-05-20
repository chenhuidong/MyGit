#include "../../stdafx.h"

int main(int argc, char* argv[]) {
     // Initialize Google's logging library.
	FLAGS_logtostderr = 0;
	FLAGS_log_dir = "$WORKPATH/Log";
	google::InitGoogleLogging(argv[0]);

	LOG_INFO << "Hello, Glog!";
}