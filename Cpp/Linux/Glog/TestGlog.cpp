#include <glog/logging.h>
#include "MyLog.h"

int main(int argc, char* argv[]) {
     // Initialize Google's logging library.
	FLAGS_logtostderr = 0;
	FLAGS_log_dir = "/home/51linux_LxomB0aQ/MyProgram/MyGit/Cpp/Linux/Glog";
	google::InitGoogleLogging(argv[0]);

     // ...
	LOG_INFO << "Hello, Glog!";
}