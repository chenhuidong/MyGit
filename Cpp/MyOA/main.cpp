#include "MyData.h"
#include "MyTable.h"
#include "MyException.h"
#include <stdio.h>
#include <unistd.h>


int main()
{
	MyData t_oMyData;
	t_oMyData.Initialize("employee.db");

	//create table
    *t_oMyData.GetSession() << "CREATE TABLE IF NOT EXISTS Employee (Empno int, Name VARCHAR(30), Email VARCHAR, ValidFlag interger(1) default 0)", now;
    *t_oMyData.GetSession() << "CREATE TABLE IF NOT EXISTS Email (Sender VARCHAR(30) primary key, Password VARCHAR(30), Mailhost VARCHAR(30))", now;
    
    
    Emails t_outEmails;
    Employees t_outEmployees;
    TEmails t_oTEmails;
    TEmployees t_oTEmployees;

    try
    {
        t_oTEmails.SelectData(t_oMyData, t_outEmails);
        t_oTEmployees.SelectData(t_oMyData, t_outEmployees);
    }
    catch (Poco::NoRecordException& exc)
    {
        std::cerr << exc.displayText() << std::endl;
        t_oMyData.Uninitialize();
        return -1;
    }


    int t_outEmailsSize = t_outEmails.size();
    int t_outEmployeesSize = t_outEmployees.size();

    for (int i = 0; i < t_outEmployeesSize; i++)
    {
        int j = i % t_outEmailsSize;
        std::cout << "Empno: " << t_outEmployees[i].get<0>() << 
            ", Name: " << t_outEmployees[i].get<1>() << 
            ", Email: " << t_outEmployees[i].get<2>() << std::endl;

        std::cout << "Sender: " << t_outEmails[j].get<0>() << 
            ", Password: " << t_outEmails[j].get<1>() << 
            ", Mailhost: " << t_outEmails[j].get<2>() << std::endl <<std::endl;

        if(j == t_outEmailsSize-1)
            sleep(2);
    }

    t_oMyData.Uninitialize();

	return 0;
}

//g++ main.cpp  MyData.cpp MyException.cpp -omain -lPocoDataSQLite -lPocoFoundation
