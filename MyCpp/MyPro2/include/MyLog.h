#ifndef __MY_LIB_MY_LOG_H_
#define __MY_LIB_MY_LOG_H_

#include "MyStdAfx.h"
#include <log4cpp/Category.hh>
#include <log4cpp/PropertyConfigurator.hh>

namespace MMyLib
{
	//#define LOG_INFO(format, ...)  pLog->info(format, ##__VA_ARGS__)
	//#define LOG_WARN MMyLib::pLog->warn
	//#define LOG_ERROR MMyLib::pLog->error
	//#define LOG_FATAL MMyLib::pLog->fatal
 	#define MyLogNull pLog = NULL

	int InitLog(const char * in_sInitFileName);
	int UninitLog();

	extern log4cpp::Category* pLog;
};	

#endif