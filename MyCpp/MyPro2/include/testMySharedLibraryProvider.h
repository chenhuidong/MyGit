#ifndef __MY_LIB_TEST_MY_SHARED_LIBRARY_H_
#define __MY_LIB_TEST_MY_SHARED_LIBRARY_H_

#include "MyStdAfx.h"
#include "MyLog.h"
#include "Poco/ClassLibrary.h"
#include <iostream>

using namespace MMyLib;

#if defined(_WIN32)
#define LIBRARY_API __declspec(dllexport)
#else
#define LIBRARY_API
#endif
extern "C" int LIBRARY_API hellokitty();

class AbstractPlugin
{
public:
	AbstractPlugin();
	virtual ~AbstractPlugin();
	virtual void HelloWorld() = 0;
};

class PluginA: public AbstractPlugin
{
public:
	PluginA();
	virtual ~PluginA();

	void HelloWorld();
};

#endif
//g++ testSharedLibraryProvider.cpp -fPIC -shared -o libtestSharedLibrary.so