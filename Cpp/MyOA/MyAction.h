#ifndef __MY_ACTION_H_
#define __MY_ACTION_H_

#include "../stdafx.h"
#include <fstream>
#include "MyData.h"
#include "MyException.h"
#include "MyEmail.h"
#include "MyStruct.h"

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
	MyData m_oMyData;
	Emails m_oEmails;
	Employees m_oEmployees;
	Salarys m_oSalarys;
};

#endif 