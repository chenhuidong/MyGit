#include "MyAction.h"

int MyAction::InitializeDb(const char* in_sDbName)
{
	m_oMyDb.Initialize(in_sDbName);
	return 0;
}

int MyAction::Install()
{
	//create table
	*m_oMyDb.GetSession() << "CREATE TABLE IF NOT EXISTS Employees (Empno int, Name VARCHAR(256), Email VARCHAR(256), ValidFlag interger(1) default 0)", now;
    *m_oMyDb.GetSession() << "CREATE TABLE IF NOT EXISTS Emails (Sender VARCHAR(256) primary key, Password VARCHAR(256), Mailhost VARCHAR(256))", now;
    *m_oMyDb.GetSession() << "CREATE TABLE IF NOT EXISTS Salarys (Empno int, BaseSalary int, Performance int, BaseTotal int, EndowmentInsurance int, UnemployedInsurance int, MedicalInsurance int, HousingInsurance int, SocialInsuranceTotal int, IncomeTax int, OtherPay int, ActualSalary int)", now;
    return 0;
}

int MyAction::SelectData()
{
	m_oMyDb.ExecuteSQL("SELECT Empno, Name, Email FROM Employees where ValidFlag = 0", m_oEmployees);
    if(m_oEmployees.empty())
    {
    	throw Poco::NoRecordException("Employees no record.");
    }

    m_oMyDb.ExecuteSQL("SELECT * FROM Emails", m_oEmails);
    if(m_oEmails.empty())
    {
    	throw Poco::NoRecordException("Emails no record.");
    }

    m_oMyDb.ExecuteSQL("SELECT * FROM Salarys", m_oSalarys);
    if(m_oSalarys.empty())
    {
        throw Poco::NoRecordException("Salarys no record.");
    }
    return 0;
}

int MyAction::UninitializeDb()
{
	m_oMyDb.Uninitialize();
	return 0;
}

int MyAction::InsertData()
{
	char iSQL[1024] = {0};
	snprintf(iSQL, sizeof(iSQL), "INSERT INTO Employees (Empno, Name, Email) VALUES(%d, \'%s\', \'%s\')", 2, "cccc", "fdsfs@163.com");
    m_oMyDb.ExecuteSQL(iSQL, m_oEmployees);

   	snprintf(iSQL, sizeof(iSQL), "INSERT INTO Emails (Sender, Password, Mailhost) VALUES(\'%s\', \'%s\', \'%s\')", "chdyczx@live.com", "cccc", "smtp@163.com");
    m_oMyDb.ExecuteSQL(iSQL, m_oEmails);

    snprintf(iSQL, sizeof(iSQL), "INSERT INTO Salarys VALUES(%d, %d, %d, %d, %d, %d, %d, %d, %d, %d, %d, %d)", 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12);
    m_oMyDb.ExecuteSQL(iSQL, m_oEmails);
    return 0;
}

int MyAction::DeleteEmployee(int in_iEmpno)
{
	char iSQL[1024] = {0};
	snprintf(iSQL, sizeof(iSQL), "UPDATE Employees set ValidFlag = 1 where Empno = %d", in_iEmpno);
	m_oMyDb.ExecuteSQL(iSQL, m_oEmployees);
	return 0;
}

int MyAction::UpdateEmployee()
{
    return 0;
}

int MyAction::SelectEmployee(int in_iEmpno)
{
    char iSQL[1024] = {0};
    snprintf(iSQL, sizeof(iSQL), "SELECT Empno, Name, Email FROM Employees where ValidFlag = 0 and Empno = %d", in_iEmpno);

    m_oMyDb.ExecuteSQL(iSQL, m_oEmployees);
    /*
    for (Employees::const_iterator it = m_oEmployees.begin(); it != m_oEmployees.end(); ++it)
    {
        std::cout << "Empno: " << it->get<0>() << 
            ", Name: " << it->get<1>() << 
            ", Email: " << it->get<2>() << std::endl;
    }
    */
    return 0;
}

int MyAction::SendEmail()
{   
    /*
    for (Employees::const_iterator it = m_oEmployees.begin(); it != m_oEmployees.end(); ++it)
    {
        std::cout << "Empno: " << it->get<0>() << 
            ", Name: " << it->get<1>() << 
            ", Email: " << it->get<2>() << std::endl;
    }

    for (Emails::const_iterator it = m_oEmails.begin(); it != m_oEmails.end(); ++it)
    {
        std::cout << "Sender: " << it->get<0>() << 
            ", Password: " << it->get<1>() << 
            ", Mailhost: " << it->get<2>() << std::endl;
    }
    */
    MyEmail t_oMyEmail;
    t_oMyEmail.SendEmails(this);
    return 0;
}
