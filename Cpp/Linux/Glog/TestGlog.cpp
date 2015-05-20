#include <glog/logging.h>

int main(int argc, char* argv[]) {
     // Initialize Google's logging library.
	FLAGS_logtostderr = 0;
	FLAGS_log_dir = "~/MyProgram/MyGit/Cpp/Linux/Glog";
	google::InitGoogleLogging(argv[0]);

     // ...
	LOG(INFO) << "Hello, Glog!";
}