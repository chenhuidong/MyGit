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

struct SEmployee
{
	int			Empno;
	std::string Name;
	std::string Email;
};

class OPTEmployee
{
public:
	OPTEmployee(Session *in_pSession):m_pSession(in_pSession){}
	//int ImportData();
	int InsertData(Employees &in_oEmployees);
	int SelectData(Employees &out_oEmployees);
	int DeleteData(int in_iEmpno);
	int UpdateData(SEmployee &in_oSEmployee);
private:
	Session *m_pSession;
};

#endif