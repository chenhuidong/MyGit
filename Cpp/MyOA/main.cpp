#include "MyData.h"
#include "MyEmployee.h"
#include <stdio.h>
#include "Poco/Exception.h"
#include <typeinfo>

typedef Poco::Tuple<int, std::string, std::string> Employee;
typedef std::vector<Employee> Employees;

typedef Poco::Tuple<std::string, std::string, std::string> MyEmail;
typedef std::vector<MyEmail> MyEmails;

POCO_IMPLEMENT_EXCEPTION(NoRecordException, Exception, "Email address is empty.")

int main()
{
	MyData t_oMyData;
	t_oMyData.Initialize("employee.db");

	//create table
    *t_oMyData.GetSession() << "CREATE TABLE IF NOT EXISTS Employee (Empno int, Name VARCHAR(30), Email VARCHAR, ValidFlag interger(1) default 0)", now;
    *t_oMyData.GetSession() << "CREATE TABLE IF NOT EXISTS MyEail (Sender VARCHAR(30) primary key, Password VARCHAR(30), Mailhost VARCHAR(30))", now;
    
    /*
    Employees t_outEmployees;

    char iSQL[1024] = {0};
    snprintf(iSQL, sizeof(iSQL), "INSERT INTO Employee (Empno, Name, Email) VALUES(%d, \'%s\', \'%s\')", 2, "cccc", "fdsfs@163.com");
    t_oMyData.ExecuteSQL(iSQL, t_outEmployees);
    t_outEmployees.clear();
    
    t_oMyData.ExecuteSQL("SELECT Empno, Name, Email FROM Employee where ValidFlag = 0", t_outEmployees);
    for (Employees::const_iterator it = t_outEmployees.begin(); it != t_outEmployees.end(); ++it)
    {
        std::cout << "Empno: " << it->get<0>() << 
            ", Name: " << it->get<1>() << 
            ", Email: " << it->get<2>() << std::endl;
    }
    t_outEmployees.clear();
    */
    char iSQL[1024] = {0};
    MyEmails t_outMyEmails;
    snprintf(iSQL, sizeof(iSQL), "SELECT * FROM MyEail");
    t_oMyData.ExecuteSQL(iSQL, t_outMyEmails);
    
    /*
    for (MyEmails::const_iterator it = t_outMyEmails.begin(); it != t_outMyEmails.end(); ++it)
    {
        std::cout << "Sender: " << it->get<0>() << 
            ", Password: " << it->get<1>() << 
            ", Mailhost: " << it->get<2>() << std::endl;
    }
    */
    try
    {
        if(t_outMyEmails.empty())
        {
            //std::cout<< "Email address is empty." <<std::endl;
            //t_oMyData.Uninitialize();
            //return -1;
            throw NoRecordException();
        }
    }
    catch (Exception& exc)
    {
        std::cerr << exc.displayText() << std::endl;
        t_oMyData.Uninitialize();
        return -1;
    }

    t_oMyData.Uninitialize();

	return 0;
}

//g++ main.cpp  MyData.cpp -omain -lPocoDataSQLite
