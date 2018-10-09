#ifndef __MY_START_H_
#define __MY_START_H_

#include "MyStdAfx.h"
#include "MyLog.h"
#include "MyDb.h"
#include <iostream>
using namespace MMyLib;

typedef Poco::Tuple<int, std::string> task_param;
typedef std::vector<task_param> task_params;

class MyStart
{
public:
	int InitializeAll();
	int UninitializeAll();
	int ChooseTask();
private:
	MMyLib::MyDb m_oMyDb;
	task_params m_oTaskParams;
//private:
};
#endif