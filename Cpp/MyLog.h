#ifndef __MY_LOG_H_
#define __MY_LOG_H_
//GLog
#include <glog/logging.h>

//Glog
#define LOG_INFO LOG(INFO)
#define LOG_WARN LOG(WARNING)
#define LOG_ERROR LOG(ERROR)
#define LOG_FATAL LOG(FATAL)

#define INITIALIZE_LOG() INITIALIZE_LOG1(argv[0])

#define INITIALIZE_LOG1(link)\
{\
	google::InitGoogleLogging(link);\
	FLAGS_logtostderr = 0;\
	FLAGS_alsologtostderr=0;\
	FLAGS_stderrthreshold=google::FATAL;\
	FLAGS_minloglevel=google::INFO;\
	string t_strLogPath = getenv("LOGPATH");\
	FLAGS_log_dir = t_strLogPath;\
	google::SetLogDestination(google::INFO, (string(FLAGS_log_dir)+"/"+link+".info.").c_str());\
	google::SetLogDestination(google::WARNING, (string(FLAGS_log_dir)+"/"+link+".warning.").c_str());\
	google::SetLogDestination(google::ERROR, (string(FLAGS_log_dir)+"/"+link+".error.").c_str());\
	google::SetLogDestination(google::FATAL, (string(FLAGS_log_dir)+"/"+link+".fatal.").c_str());\
}

#endif