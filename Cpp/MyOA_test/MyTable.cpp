#include "MyTable.h"

int TEmployees::SelectData(MyData &t_inMyData, Employees& t_outEmployees)
{
	char iSQL[1024] = {0};
	snprintf(iSQL, sizeof(iSQL), "SELECT Empno, Name, Email FROM Employee where ValidFlag = 0");
    t_inMyData.ExecuteSQL(iSQL, t_outEmployees);

    if(t_outEmployees.empty())
    {
    	throw Poco::NoRecordException("Employee no record.");
    }
	return 0;
}

int TEmployees::ImportData(MyData &t_inMyData, Employees& t_inEmployees)
{
    Statement t_oInsertStatement(*t_inMyData.GetSession());
    t_oInsertStatement << "INSERT INTO Employee (Empno, Name, Email) VALUES(:Empno, :Name, :Email)",
        use(t_inEmployees), now;
    return 0;
}

int TEmails::SelectData(MyData &t_inMyData, Emails& t_outEmails)
{
	char iSQL[1024] = {0};
	snprintf(iSQL, sizeof(iSQL), "SELECT * FROM Email");
    t_inMyData.ExecuteSQL(iSQL, t_outEmails);

    if(t_outEmails.empty())
    {
    	throw Poco::NoRecordException("Email no record.");
    }
	return 0;
}




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

    /*
    for (Emails::const_iterator it = t_outEmails.begin(); it != t_outEmails.end(); ++it)
    {
        std::cout << "Sender: " << it->get<0>() << 
            ", Password: " << it->get<1>() << 
            ", Mailhost: " << it->get<2>() << std::endl;
    }
    */