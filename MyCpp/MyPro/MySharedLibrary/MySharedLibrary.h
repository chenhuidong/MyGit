#ifndef __MY_LIB_MY_SHARED_LIBRARY_H_
#define __MY_LIB_MY_SHARED_LIBRARY_H_

#include "MyStdAfx.h"
#include "Poco/SharedLibrary.h"

using Poco::SharedLibrary;

namespace MMyLib
{
class IMySharedLibrary
{
public:
	IMySharedLibrary(string in_sPathName);
	virtual ~IMySharedLibrary();
private:
	SharedLibrary m_oLibrary;
};
};

#endif