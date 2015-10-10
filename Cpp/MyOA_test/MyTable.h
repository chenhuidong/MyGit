#ifndef __MY_OA_MY_TABLE_H_
#define __MY_OA_MY_TABLE_H_

#include "MyData.h"
#include "MyException.h"
#include <stdio.h>
#include <unistd.h>

typedef Poco::Tuple<int, std::string, std::string> Employee;
typedef std::vector<Employee> Employees;

typedef Poco::Tuple<std::string, std::string, std::string> Email;
typedef std::vector<Email> Emails;

class TTable
{
//public:
//	virtual int SelectData() = 0;
};

class TEmployees: public TTable
{
public:
	int SelectData(MyData &t_inMyData, Employees& t_outEmployees);
	int InsertData(MyData &t_inMyData, Employees& t_inEmployees);
	int ImportData(MyData &t_inMyData, Employees& t_inEmployees);
};


class TEmails: public TTable
{
public:
	int SelectData(MyData &t_inMyData, Emails& t_outEmails);
};


#endif