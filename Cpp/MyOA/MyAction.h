#ifndef __MY_ACTION_H_
#define __MY_ACTION_H_

#include "../stdafx.h"
#include <fstream>
#include "MyDb.h"
#include "MyException.h"
#include "MyEmail.h"
#include "MyStruct.h"
#include "MyData.h"
#include "Poco/Thread.h"
#include "Poco/Runnable.h"
#include "../MyLog.h"


class MyAction
{
public:
	MyAction(){}
	~MyAction(){}

	int Initialize(const char* in_sLogName, const char* in_sDbName);
	int Install();
	int SelectData();
	int InsertData();

	int SelectEmployee(int in_iEmpno);
	int DeleteEmployee(int in_iEmpno);
	int UpdateEmployee();
	
	int SendEmail();

	/*
	int ImportData();
	*/
	int UninitializeDb();
private:
	int InitializeDb(const char* in_sDbName);

public:
	MyDatas m_oMyDatas;
private:
	MyDb m_oMyDb;
};

#endif 