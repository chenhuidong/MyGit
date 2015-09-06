#ifndef __MY_OA_MY_EMPLOYEE_H_
#define __MY_OA_MY_EMPLOYEE_H_

#include "Poco/Data/Session.h"
#include "Poco/Data/SessionFactory.h"
#include "Poco/Data/SQLite/Connector.h"
#include <vector>
#include <iostream>

using namespace Poco::Data::Keywords;
using Poco::Data::Session;
using Poco::Data::Statement;

struct Employee
{
	int			empno;
	std::string name;
	std::string email;
};

class TEmployee
{
public:
	TEmployee(Session *pSession):m_oStatement(*pSession){}
	//int ImportData();
	int InsertData(Employee& employee);

	Statement m_oStatement;
};

#endif