#ifndef __MY_LIB_MY_LOG_H_
#define __MY_LIB_MY_LOG_H_

#include "MyStdAfx.h"
#include <log4cpp/Category.hh>
#include <log4cpp/PropertyConfigurator.hh>

namespace MMyLib
{
	#define LOG_INFO MyLog::pLog->info
	#define LOG_WARN MyLog::pLog->warn
	#define LOG_ERROR MyLog::pLog->error
	#define LOG_FATAL MyLog::pLog->fatal

	class MyLog
	{
	public:
		static int Initialize(const char * in_sFileName = NULL);
		static int Uninitialize();
		static log4cpp::Category* pLog;
	};
};

#endif