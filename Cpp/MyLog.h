#ifndef __MY_LOG_H_
#define __MY_LOG_H_
//GLog
#include <glog/logging.h>
#include <string>

//Glog
#define LOG_INFO LOG(INFO)
#define LOG_WARN LOG(WARNING)
#define LOG_ERROR LOG(ERROR)
#define LOG_FATAL LOG(FATAL)

#define INITIALIZE_LOG(filename) INITIALIZE_LOG1(filename)

#define INITIALIZE_LOG1(filename)\
{\
	google::InitGoogleLogging(filename);\
	FLAGS_logtostderr = 0;\
	FLAGS_alsologtostderr=0;\
	FLAGS_stderrthreshold=google::FATAL;\
	FLAGS_minloglevel=0;\
	string t_strLogPath = getenv("LOGPATH");\
	FLAGS_log_dir = t_strLogPath;\
	string t_strInfoName, t_strWarningName, t_strErrorName, t_strFatalName;\
	#if defined (FLAGS_SEPARATE_INFO) \
		t_strInfoName=t_strInfoName+FLAGS_log_dir+"/"+filename+".info.";\
	#endif\
	google::SetLogDestination(google::INFO, t_strInfoName.c_str());\
	google::SetLogDestination(google::WARNING, t_strWarningName.c_str());\
	google::SetLogDestination(google::ERROR, t_strErrorName.c_str());\
	google::SetLogDestination(google::FATAL, t_strFatalName.c_str());\
}
/*
	#ifdef FLAGS_SEPARATE_INFO \
		t_strInfoName=t_strInfoName+FLAGS_log_dir+"/"+filename+".info.";\
	#elif FLAGS_SEPARATE_WARNING \
		t_strWarningName=t_strWarningName+FLAGS_log_dir+"/"+filename+".warning.";\
	#elif FLAGS_SEPARATE_ERROR \
		t_strErrorName=t_strErrorName+FLAGS_log_dir+"/"+filename+".error.";\
	#elif FLAGS_SEPARATE_FATAL \
		t_strFatalName=t_strFatalName+FLAGS_log_dir+"/"+filename+".fatal.";\
	#else
		t_strInfoName=t_strInfoName+FLAGS_log_dir+"/"+filename+".info.";\
		t_strWarningName=t_strWarningName+FLAGS_log_dir+"/"+filename+".warning.";\
		t_strErrorName=t_strErrorName+FLAGS_log_dir+"/"+filename+".error.";\
		t_strFatalName=t_strFatalName+FLAGS_log_dir+"/"+filename+".fatal.";\
	#endif \
	*/
/*	google::SetLogDestination(google::INFO, (string(FLAGS_log_dir)+"/"+filename+".info.").c_str());\
	google::SetLogDestination(google::WARNING, (string(FLAGS_log_dir)+"/"+filename+".warning.").c_str());\
	google::SetLogDestination(google::ERROR, (string(FLAGS_log_dir)+"/"+filename+".error.").c_str());\
	google::SetLogDestination(google::FATAL, (string(FLAGS_log_dir)+"/"+filename+".fatal.").c_str());\
	*/
#endif