#ifndef __MY_STRUCT_H_
#define __MY_STRUCT_H_

typedef Poco::Tuple<int, std::string, std::string> Employee;
typedef std::vector<Employee> Employees;

typedef Poco::Tuple<std::string, std::string, std::string> Email;
typedef std::vector<Email> Emails;

typedef Poco::Tuple<int, int, int, int, int, int, int, int, int, int, int, int> Salary;
typedef std::vector<Email> Salarys;

#endif