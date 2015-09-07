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
/*
struct Employee
{
	int			empno;
	std::string name;
	std::string email;
};
*/
typedef Poco::Tuple<int, std::string, std::string, int> Employee;
typedef std::vector<Employee> Employees;

class OPTEmployee
{
public:
	OPTEmployee(Session *in_pSession): m_oInsertStatement(*in_pSession) ,m_oSelectStatement(*in_pSession){}
	//int ImportData();
	int InsertData();
	int DeleteData();
	int SelectData();

	Employees m_oEmployees;

	Statement m_oInsertStatement;
	Statement m_oSelectStatement;
};

#endif