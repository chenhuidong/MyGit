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

static void INITIALIZE_LOG(char * filename)
{
	google::InitGoogleLogging(filename);

	FLAGS_logtostderr = 0;
	FLAGS_alsologtostderr=0;
	FLAGS_stderrthreshold=google::FATAL;
	FLAGS_minloglevel=0;
	string t_strLogPath = getenv("LOGPATH");
	FLAGS_log_dir = t_strLogPath;

	string t_strInfoName, t_strWarningName, t_strErrorName, t_strFatalName;
	#ifdef FLAGS_INFO //info以上单日志
		t_strInfoName=t_strInfoName+FLAGS_log_dir+"/"+filename+".info.";
	#elif FLAGS_WARNING //waring以上单日志
		t_strWarningName=t_strWarningName+FLAGS_log_dir+"/"+filename+".warning.";
	#elif FLAGS_ERROR //error以上单日志
		t_strErrorName=t_strErrorName+FLAGS_log_dir+"/"+filename+".error.";
	#elif FLAGS_FATAL //fatal以上单日志
		t_strFatalName=t_strFatalName+FLAGS_log_dir+"/"+filename+".fatal.";
	#elif FLAGS_ALL //各级别分别日志
		t_strInfoName=t_strInfoName+FLAGS_log_dir+"/"+filename+".info.";
		t_strWarningName=t_strWarningName+FLAGS_log_dir+"/"+filename+".warning.";
		t_strErrorName=t_strErrorName+FLAGS_log_dir+"/"+filename+".error.";
		t_strFatalName=t_strFatalName+FLAGS_log_dir+"/"+filename+".fatal.";
	#else //默认INFO单日志
		t_strInfoName=t_strInfoName+FLAGS_log_dir+"/"+filename+".info.";
	#endif 

	google::SetLogDestination(google::INFO, t_strInfoName.c_str());
	google::SetLogDestination(google::WARNING, t_strWarningName.c_str());
	google::SetLogDestination(google::ERROR, t_strErrorName.c_str());
	google::SetLogDestination(google::FATAL, t_strFatalName.c_str());
}

/*	google::SetLogDestination(google::INFO, (string(FLAGS_log_dir)+"/"+filename+".info.").c_str());
	google::SetLogDestination(google::WARNING, (string(FLAGS_log_dir)+"/"+filename+".warning.").c_str());
	google::SetLogDestination(google::ERROR, (string(FLAGS_log_dir)+"/"+filename+".error.").c_str());
	google::SetLogDestination(google::FATAL, (string(FLAGS_log_dir)+"/"+filename+".fatal.").c_str());
	*/
#endif