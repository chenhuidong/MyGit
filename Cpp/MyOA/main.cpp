#include "MyData.h"
#include "MyException.h"
#include <stdio.h>
#include <unistd.h>


int main()
{
	MyData t_oMyData;
	t_oMyData.Initialize("employee.db");

	//create table
    *t_oMyData.GetSession() << "CREATE TABLE IF NOT EXISTS Employee (Empno int, Name VARCHAR(256), Email VARCHAR(256), ValidFlag interger(1) default 0)", now;
    *t_oMyData.GetSession() << "CREATE TABLE IF NOT EXISTS Email (Sender VARCHAR(256) primary key, Password VARCHAR(256), Mailhost VARCHAR(256))", now;
    
    char iSQL[1024] = {0};
    
    Employees t_outEmployees;

    //snprintf(iSQL, sizeof(iSQL), "INSERT INTO Employee (Empno, Name, Email) VALUES(%d, \'%s\', \'%s\')", 2, "cccc", "fdsfs@163.com");
    //t_oMyData.ExecuteSQL(iSQL, t_outEmployees);

    t_oMyData.ExecuteSQL("SELECT Empno, Name, Email FROM Employee where ValidFlag = 0", t_outEmployees);
    /*
    for (Employees::const_iterator it = t_outEmployees.begin(); it != t_outEmployees.end(); ++it)
    {
        std::cout << "Empno: " << it->get<0>() << 
            ", Name: " << it->get<1>() << 
            ", Email: " << it->get<2>() << std::endl;
    }
	*/
    if(t_outEmployees.empty())
    {
    	throw Poco::NoRecordException("Email no record.");
    }


	Emails t_outEmails;

	snprintf(iSQL, sizeof(iSQL), "INSERT INTO Email (Sender, Password, Mailhost) VALUES(%d, \'%s\', \'%s\')", "chdyczx@live.com", "cccc", "smtp@163.com");
    t_oMyData.ExecuteSQL(iSQL, t_outEmployees);

	snprintf(iSQL, sizeof(iSQL), "SELECT * FROM Email");
    t_oMyData.ExecuteSQL(iSQL, t_outEmails);

    for (Emails::const_iterator it = t_outEmails.begin(); it != t_outEmails.end(); ++it)
    {
        std::cout << "Sender: " << it->get<0>() << 
            ", Password: " << it->get<1>() << 
            ", Mailhost: " << it->get<2>() << std::endl;
    }

    if(t_outEmails.empty())
    {
    	throw Poco::NoRecordException("Email no record.");
    }

    t_oMyData.Uninitialize();

	return 0;
}

//g++ main.cpp  MyData.cpp MyTable.cpp MyException.cpp -omain -lPocoDataSQLite -lPocoFoundation
