#include "MyAction.h"

int MyAction::InitializeDb(const char* in_sDbName)
{
	m_oMyData.Initialize(in_sDbName);
}

int MyAction::Install()
{
	//create table
	*m_oMyData.GetSession() << "CREATE TABLE IF NOT EXISTS Employee (Empno int, Name VARCHAR(256), Email VARCHAR(256), ValidFlag interger(1) default 0)", now;
    *m_oMyData.GetSession() << "CREATE TABLE IF NOT EXISTS Email (Sender VARCHAR(256) primary key, Password VARCHAR(256), Mailhost VARCHAR(256))", now;
}

int MyAction::SelectData()
{
	m_oMyData.ExecuteSQL("SELECT Empno, Name, Email FROM Employee where ValidFlag = 0", m_oEmployees);

	for (Employees::const_iterator it = m_oEmployees.begin(); it != m_oEmployees.end(); ++it)
    {
        std::cout << "Empno: " << it->get<0>() << 
            ", Name: " << it->get<1>() << 
            ", Email: " << it->get<2>() << std::endl;
    }

    t_oMyData.ExecuteSQL("SELECT * FROM Email", m_oEmails);

    for (Emails::const_iterator it = m_oEmails.begin(); it != m_oEmails.end(); ++it)
    {
        std::cout << "Sender: " << it->get<0>() << 
            ", Password: " << it->get<1>() << 
            ", Mailhost: " << it->get<2>() << std::endl;
    }
}

int MyAction::UninitializeDb()
{
	m_oMyData.Uninitialize();
}