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

		int GetXMLPath(int in_iConditionId);
		string& GetCurLib();
		string& GetCurInterface();
	private:
		string m_sXMLPath;
	};
};

#endif
