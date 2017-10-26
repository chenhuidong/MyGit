#ifndef __MY_LIB_MY_LOG_H_
#define __MY_LIB_MY_LOG_H_

#include "MyStdAfx.h"
#include <log4cpp/Category.hh>
#include <log4cpp/PropertyConfigurator.hh>

namespace MMyLib
{
	//#define LOG_INFO LOG(INFO)
	//#define LOG_WARN LOG(WARNING)
	//#define LOG_ERROR LOG(ERROR)
	//#define LOG_FATAL LOG(FATAL)

	//root.warn("Storm is coming");

	class MyLog
	{
	public:
		static int Initialize(const char * in_sFileName = NULL);
		static int Uninitialize();
		static log4cpp::Category* pLog;
	};
};

#endif