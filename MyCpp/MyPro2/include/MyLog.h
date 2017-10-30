#ifndef __MY_LIB_MY_LOG_H_
#define __MY_LIB_MY_LOG_H_

#include "MyStdAfx.h"
#include <log4cpp/Category.hh>
#include <log4cpp/PropertyConfigurator.hh>

namespace MMyLib
{
	#define LOG_INFO pLog->info
	#define LOG_WARN pLog->warn
	#define LOG_ERROR pLog->error
	#define LOG_FATAL pLog->fatal
 
	extern "C" int __declspec(dllexport) Initialize(const char * in_sFileName = NULL);
	extern "C" int __declspec(dllexport) Uninitialize();
	static log4cpp::Category* pLog;

};

#endif