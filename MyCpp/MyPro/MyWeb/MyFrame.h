#ifndef __MY_LIB_MY_FRAME_H_
#define __MY_LIB_MY_FRAME_H_

#include "MyStdAfx.h"
#include "MyRedis.h"
#include "MyConf.h"
#include "MySharedLibrary.h"

namespace MMyLib
{
	class IMyFrame
	{
	public:
		IMyFrame();
		virtual ~IMyFrame();

		string& GetXMLPath(const char* in_iConditionId);
		ptree* ParseXML();
		int BeginTask(int in_iConditionId);
	private:
		string 	m_sXMLPath;
		IMyConf m_oMyConf;
	};
};

#endif
