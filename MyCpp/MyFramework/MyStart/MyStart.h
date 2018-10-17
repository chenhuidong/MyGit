#ifndef __MY_START_H_
#define __MY_START_H_

#include "MyStdAfx.h"
#include "MyLog.h"
#include "MyDb.h"
#include "MySharedLibrary.h"
#include <iostream>
using namespace MMyLib;

typedef Poco::Tuple<int, std::string> task_param;
typedef std::vector<task_param> task_params;

typedef Poco::Tuple<int, std::string, int, std::string, int, std::string, std::string, std::string, std::string> task_paramtotal;
typedef std::vector<task_paramtotal> task_paramtotals;

#define BUFSIZE 256

class MyStart
{
public:
	int InitializeAll();
	int UninitializeAll();
	int ChooseTask();
	int BeginTask(int in_iTaskCode);
private:
	MMyLib::MyDb m_oMyDb;
	task_params m_oTaskParams;
	task_paramtotals m_oTaskParamTotals;
//private:
};
#endif