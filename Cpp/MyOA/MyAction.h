#ifndef __MY_ACTION_H_
#define __MY_ACTION_H_

#include "../stdafx.h"
#include <fstream>
#include "MyDb.h"
#include "MyException.h"
#include "MyEmail.h"
#include "MyStruct.h"
#include "Poco/Thread.h"
#include "Poco/Runnable.h"

class MyAction
{
public:
	MyAction(){}
	~MyAction(){}

	int InitializeDb(const char* in_sDbName);
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

public:
	MyDb m_oMyDb;
	Emails m_oEmails;
	Employees m_oEmployees;
	Salarys m_oSalarys;
};

#endif 