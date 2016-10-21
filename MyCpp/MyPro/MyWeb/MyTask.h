#ifndef __MY_LIB_MY_TASK_H_
#define __MY_LIB_MY_TASK_H_

#include "MyStdAfx.h"
#include "MyRedis.h"
#include "MyConf.h"
#include "MySharedLibrary.h"

namespace MMyLib
{
	class IMyTask
	{
	public:
		IMyTask();
		virtual ~IMyTask();

		int BeginNewTask(int in_iConditionId);
	private:
		string& GetXMLPath(int in_iConditionId);
		ptree* ParseXML();
		
	private:
		string 	m_sXMLPath;
		IMyConf m_oMyConf;
	};
};

#endif
