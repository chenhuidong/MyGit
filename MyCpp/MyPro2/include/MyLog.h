#ifndef __MY_LIB_MY_LOG_H_
#define __MY_LIB_MY_LOG_H_

#include "MyStdAfx.h"
#include <log4cpp/Category.hh>
#include <log4cpp/PropertyConfigurator.hh>

namespace MMyLib
{
	#define LOG_INFO(format, ...)  pLog->info(format, ##__VA_ARGS__)
	#define LOG_WARN(format, ...)  pLog->warn(format, ##__VA_ARGS__)
	#define LOG_ERROR(format, ...) pLog->error(format, ##__VA_ARGS__)
	#define LOG_FATAL(format, ...) pLog->fatal(format, ##__VA_ARGS__)

	int InitLog(const char * in_sInitFileName);
	int UninitLog();

	extern log4cpp::Category* pLog;
};	

#endif