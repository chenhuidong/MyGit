#include <glog/logging.h>

int main(int argc, char* argv[]) {
     // Initialize Google's logging library.
	FLAGS_logtostderr = 1;
	google::InitGoogleLogging(argv[0]);

     // ...
	LOG(INFO) << "Hello, Glog!";
}