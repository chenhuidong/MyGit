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
	TEmployee(Session *in_pSession):m_oInsertStatement(*in_pSession), m_oSelectStatement(*in_pSession){}
	//int ImportData();
	int InsertData(Employee& in_oEmployee);
	int DeleteData();
	int SelectData();


	Statement m_oInsertStatement;
	Statement m_oSelectStatement;
};

#endif