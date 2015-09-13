#include "MyData.h"
#include "MyEmployee.h"
#include "MyException.h"
#include <stdio.h>


typedef Poco::Tuple<int, std::string, std::string> Employee;
typedef std::vector<Employee> Employees;

typedef Poco::Tuple<std::string, std::string, std::string> MyEmail;
typedef std::vector<MyEmail> MyEmails;


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
            throw Poco::NoRecordException("MyEail no record.");
        }
    }
    catch (Poco::NoRecordException& exc)
    {
        std::cerr << exc.displayText() << std::endl;
        t_oMyData.Uninitialize();
        return -1;
    }


    Employees t_outEmployees;
    snprintf(iSQL, sizeof(iSQL), "SELECT Empno, Name, Email FROM Employee");
    t_oMyData.ExecuteSQL(iSQL, t_outEmployees);
    
    /*
    for (Employees::const_iterator it = t_outEmployees.begin(); it != t_outEmployees.end(); ++it)
    {
        std::cout << "Empno: " << it->get<0>() << 
            ", Name: " << it->get<1>() << 
            ", Email: " << it->get<2>() << std::endl;
    }
    */
    try
    {
        if(t_outEmployees.empty())
        {
            throw Poco::NoRecordException("Employee no record.");
        }
    }
    catch (Poco::NoRecordException& exc)
    {
        std::cerr << exc.displayText() << std::endl;
        t_oMyData.Uninitialize();
        return -1;
    }


    std::cout<< t_outMyEmails.size() <<std::endl;
    std::cout<< t_outEmployees.size() <<std::endl;

    /*
    for (MyEmails::const_iterator it_MyEmails = t_outMyEmails.begin(); it_MyEmails != t_outMyEmails.end(); ++it_MyEmails)
    {
        std::cout << "Sender: " << it_MyEmails->get<0>() << 
            ", Password: " << it_MyEmails->get<1>() << 
            ", Mailhost: " << it_MyEmails->get<2>() << std::endl;

        for (Employees::const_iterator it_Employees = t_outEmployees.begin(); it_Employees != t_outEmployees.end(); ++it_Employees)
        {
            std::cout << "Empno: " << it->get<0>() << 
                ", Name: " << it->get<1>() << 
                ", Email: " << it->get<2>() << std::endl;
        }
    }
    */


    t_oMyData.Uninitialize();

	return 0;
}

//g++ main.cpp  MyData.cpp MyException.cpp -omain -lPocoDataSQLite -lPocoFoundation
