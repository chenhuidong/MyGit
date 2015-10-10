#include "../stdafx.h"
#include "MyData.h"
#include "MyException.h"
#include "MyAction.h"


int main(int argc, char* argv[])
{
	MyAction t_oMyAction;
	t_oMyAction.InitializeDb("employee.db");
	t_oMyAction.Install();
	t_oMyAction.SelectData();
	t_oMyAction.UninitializeDb();

    
    //char iSQL[1024] = {0};
    
    //Employees t_outEmployees;

    //snprintf(iSQL, sizeof(iSQL), "INSERT INTO Employee (Empno, Name, Email) VALUES(%d, \'%s\', \'%s\')", 2, "cccc", "fdsfs@163.com");
    //t_oMyData.ExecuteSQL(iSQL, t_outEmployees);


	//Emails t_outEmails;

	//snprintf(iSQL, sizeof(iSQL), "INSERT INTO Email (Sender, Password, Mailhost) VALUES(%d, \'%s\', \'%s\')", "chdyczx@live.com", "cccc", "smtp@163.com");
    //t_oMyData.ExecuteSQL(iSQL, t_outEmployees);

	/*
    if(t_outEmails.empty() || t_outEmployees.empty())
    {
    	throw Poco::NoRecordException("Email no record.");
    }
	*/

	return 0;
}
