#ifndef __MY_DTS_H_
#define __MY_DTS_H_

#include "MyStdAfx.h"
#include "MyLog.h"
#include "MyDb.h"
#include "MySharedLibrary.h"
#include "MyRedis.h"
#include "MyBaseFunc.h"
#include <iostream>
using namespace MMyLib;

typedef Poco::Tuple<int, std::string> task_param;
typedef std::vector<task_param> task_params;

typedef Poco::Tuple<int, std::string, int, std::string, int, std::string, std::string, std::string, std::string> task_paramtotal;
typedef std::vector<task_paramtotal> task_paramtotals;

#define BUFSIZE 256

class MyDTS
{
public:
	int InitializeAll();
	int UninitializeAll();
	int ChooseTask();
	int BeginTask(int in_iTaskCode);
	int BeginTask(char* in_sTaskName);

private:
	MMyLib::MyDb m_oMyDb;
	MMyLib::IMyRedis m_oMyRedis;
	task_params m_oTaskParams;
	task_paramtotals m_oTaskParamTotals;
//private:
};
#endif