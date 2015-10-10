#include "MyData.h"
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
    
    char iSQL[1024] = {0};
    
    Employees t_outEmployees;
    
    t_oMyData.ExecuteSQL("SELECT Empno, Name, Email FROM Employee where ValidFlag = 0", t_outEmployees);
    for (Employees::const_iterator it = t_outEmployees.begin(); it != t_outEmployees.end(); ++it)
    {
        std::cout << "Empno: " << it->get<0>() << 
            ", Name: " << it->get<1>() << 
            ", Email: " << it->get<2>() << std::endl;
    }
    t_outEmployees.clear();

    t_oMyData.Uninitialize();

	return 0;
}

//g++ main.cpp  MyData.cpp MyTable.cpp MyException.cpp -omain -lPocoDataSQLite -lPocoFoundation
