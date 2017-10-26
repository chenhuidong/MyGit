#ifndef __MY_LIB_MY_SHARED_LIBRARY_H_
#define __MY_LIB_MY_SHARED_LIBRARY_H_

#include "MyStdAfx.h"
#include "Poco/SharedLibrary.h"
#include "Poco/ClassLoader.h"
#include "Poco/Manifest.h"
#include "MyException.h"
//#include "testMySharedLibraryProvider.h"

using Poco::SharedLibrary;

namespace MMyLib
{
typedef int (*Func)(); 
typedef Poco::ClassLoader<AbstractPlugin> PluginLoader;
typedef Poco::Manifest<AbstractPlugin> PluginManifest;

class IMySharedLibrary
{
public:
	IMySharedLibrary(string in_sPathName);
	virtual ~IMySharedLibrary();
public:
	int ExecFunc(string in_sFuncName);
	AbstractPlugin* CreateClass(string in_sClassName);
private:
	string 		  m_sPathName;
	SharedLibrary m_oLibrary;
	PluginLoader  m_oLoader;
};
};

#endif