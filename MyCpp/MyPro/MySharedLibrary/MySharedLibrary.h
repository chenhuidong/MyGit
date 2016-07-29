#ifndef __MY_LIB_MY_SHARED_LIBRARY_H_
#define __MY_LIB_MY_SHARED_LIBRARY_H_

#include "MyStdAfx.h"
#include "Poco/SharedLibrary.h"
#include "Poco/ClassLoader.h"
#include "Poco/Manifest.h"

using Poco::SharedLibrary;

namespace MMyLib
{
typedef void (*Func)(); 

class IMySharedLibrary
{
public:
	IMySharedLibrary(string in_sPathName);
	virtual ~IMySharedLibrary();
public:
	void ExecFunc(string in_sFuncName);
	void ExecClassFunc(string in_sClassName, string in_sFuncName);
private:
	SharedLibrary m_oLibrary;
};
};

#endif