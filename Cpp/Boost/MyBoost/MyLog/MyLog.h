#ifndef __MY_LIB_MY_LOG_H_
#define __MY_LIB_MY_LOG_H_

#include "../MyStdAfx.h"
#include <glog/logging.h>

namespace MMyLib
{
	//Glog
	#define LOG_INFO LOG(INFO)
	#define LOG_WARN LOG(WARNING)
	#define LOG_ERROR LOG(ERROR)
	#define LOG_FATAL LOG(FATAL)

	static int INITIALIZE_LOG(const char * in_sFileName = NULL)
	{
		if(!in_sFileName)
			in_sFileName="main";
		google::InitGoogleLogging(in_sFileName);
		FLAGS_logtostderr = 0;	//是否打印到控制台
		FLAGS_alsologtostderr=0;	//打印到日志同时是否打印到控制台
		FLAGS_stderrthreshold=google::FATAL;	//需要打印到控制台的日志级别
		FLAGS_minloglevel=0;	//
		FLAGS_logbufsecs = 60;	//缓存的最大时长，超时会写入文件
		const char* t_sLogPath = getenv("LOG_PATH");	
		if(!t_sLogPath)
			return -1;
		FLAGS_log_dir = t_sLogPath;
		string t_strInfoName, t_strWarningName, t_strErrorName, t_strFatalName;
		#ifdef FLAGS_INFO //info以上单日志
		t_strInfoName=t_strInfoName+FLAGS_log_dir+"/"+in_sFileName+".info.";
		#elif FLAGS_WARNING //waring以上单日志
		t_strWarningName=t_strWarningName+FLAGS_log_dir+"/"+in_sFileName+".warning.";
		#elif FLAGS_ERROR //error以上单日志
		t_strErrorName=t_strErrorName+FLAGS_log_dir+"/"+in_sFileName+".error.";
		#elif FLAGS_FATAL //fatal以上单日志
		t_strFatalName=t_strFatalName+FLAGS_log_dir+"/"+in_sFileName+".fatal.";
		#elif FLAGS_ALL //各级别分别日志
		t_strInfoName=t_strInfoName+FLAGS_log_dir+"/"+in_sFileName+".info.";
		t_strWarningName=t_strWarningName+FLAGS_log_dir+"/"+in_sFileName+".warning.";
		t_strErrorName=t_strErrorName+FLAGS_log_dir+"/"+in_sFileName+".error.";
		t_strFatalName=t_strFatalName+FLAGS_log_dir+"/"+in_sFileName+".fatal.";
		#else //默认INFO单日志
		t_strInfoName=t_strInfoName+FLAGS_log_dir+"/"+in_sFileName+".info.";
		#endif 
		cout<< t_strInfoName<< endl;

		google::SetLogDestination(google::INFO, t_strInfoName.c_str());
		google::SetLogDestination(google::WARNING, t_strWarningName.c_str());
		google::SetLogDestination(google::ERROR, t_strErrorName.c_str());
		google::SetLogDestination(google::FATAL, t_strFatalName.c_str());
		return 0;
	}
};

#endif