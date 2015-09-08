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

typedef Poco::Tuple<int, std::string, std::string> Employee;
typedef std::vector<Employee> Employees;

class OPTEmployee
{
public:
	OPTEmployee(Session *in_pSession): m_oInsertStatement(*in_pSession), m_oSelectStatement(*in_pSession), m_oUpdateStatement(*in_pSession){}
	//int ImportData();
	int InsertData(Employees &in_oEmployees);
	int SelectData(Employees &out_oEmployees);
	int DeleteData(int in_iEmpno);

private:
	Statement m_oInsertStatement;
	Statement m_oSelectStatement;
	Statement m_oUpdateStatement;
};

#endif