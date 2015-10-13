#ifndef __MY_ACTION_H_
#define __MY_ACTION_H_

#include "../stdafx.h"
#include "MyData.h"
#include "MyException.h"

typedef Poco::Tuple<int, std::string, std::string> Employee;
typedef std::vector<Employee> Employees;

typedef Poco::Tuple<std::string, std::string, std::string> Email;
typedef std::vector<Email> Emails;

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
	Employees m_oEmployees;
	Emails m_oEmails;
};

#endif 