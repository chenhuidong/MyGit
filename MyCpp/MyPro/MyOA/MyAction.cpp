#include "MyAction.h"

int MyAction::Initialize(const char* in_sLogName, MyDb::DbType in_eDbType, const char* in_sDbName)
{
    MMyLib::INITIALIZE_LOG(in_sLogName);
    LOG_INFO<< "initialize log success.";

    InitializeDb(in_eDbType, in_sDbName);

    Install(in_eDbType);
    return 0;
}

int MyAction::InitializeDb(MyDb::DbType in_eDbType, const char* in_sDbName)
{
    LOG_INFO<< "initialize db begin.";
    int t_iReturn = m_oMyDb.Initialize(in_eDbType, in_sDbName);
    LOG_INFO<< "initialize db end.";
	return 0;
}

int MyAction::Uninitialize()
{
    UninitializeDb();
}

int MyAction::UninitializeDb()
{
    m_oMyDb.Uninitialize();
    return 0;
}

int MyAction::Install(MyDb::DbType in_eDbType)
{
    LOG_INFO<< "Create tables begin.";
	//create table
    
    if(MyDb::SQLite == in_eDbType)
    {
        //SQLite
        *m_oMyDb.GetSession() << "CREATE TABLE IF NOT EXISTS Employees (Empno int, Name VARCHAR(256), Email VARCHAR(256), ValidFlag interger(1) default 0)", now;
        *m_oMyDb.GetSession() << "CREATE TABLE IF NOT EXISTS Emails (Id INTEGER PRIMARY KEY autoincrement, Sender VARCHAR(256), Password VARCHAR(256), Mailhost VARCHAR(256))", now;
        *m_oMyDb.GetSession() << "CREATE TABLE IF NOT EXISTS Salarys (Empno int, BaseSalary int, Performance int, BaseTotal int, EndowmentInsurance int, UnemployedInsurance int, MedicalInsurance int, HousingInsurance int, SocialInsuranceTotal int, IncomeTax int, OtherPay int, ActualSalary int)", now;
    }
    else if(MyDb::MySQL == in_eDbType)
    {
        //MySQL
        *m_oMyDb.GetSession() << "CREATE TABLE IF NOT EXISTS Employees (Empno int, Name VARCHAR(256), Email VARCHAR(256), ValidFlag int(1) default 0)", now;
        *m_oMyDb.GetSession() << "CREATE TABLE IF NOT EXISTS Emails (Id int auto_increment, Sender VARCHAR(256), Password VARCHAR(256), Mailhost VARCHAR(256), primary key(Id))", now;
        *m_oMyDb.GetSession() << "CREATE TABLE IF NOT EXISTS Salarys (Empno int, BaseSalary int, Performance int, BaseTotal int, EndowmentInsurance int, UnemployedInsurance int, MedicalInsurance int, HousingInsurance int, SocialInsuranceTotal int, IncomeTax int, OtherPay int, ActualSalary int)", now;    
    }
    else
    {
        throw Poco::CreateTablesException("Create tables failed.");
    }

    LOG_INFO<< "Create tables end.";
    return 0;
}

int MyAction::SelectData()
{
    LOG_INFO<< "Select tables begin.";
	
    m_oMyDb.ExecuteSQL("SELECT Empno, Name, Email FROM Employees where ValidFlag = 0", m_oMyDatas.m_oEmployees);
    if(m_oMyDatas.m_oEmployees.empty())
    {
    	throw Poco::NoRecordException("Employees no record.");
    }
    

    m_oMyDb.ExecuteSQL("SELECT Sender, Password, Mailhost FROM Emails", m_oMyDatas.m_oEmails);
    if(m_oMyDatas.m_oEmails.empty())
    {
    	throw Poco::NoRecordException("Emails no record.");
    }

    m_oMyDb.ExecuteSQL("SELECT * FROM Salarys", m_oMyDatas.m_oSalarys);
    if(m_oMyDatas.m_oSalarys.empty())
    {
        throw Poco::NoRecordException("Salarys no record.");
    }
    LOG_INFO<< "Select tables end.";
    return 0;
}

int MyAction::InsertData()
{
	char iSQL[1024] = {0};
	snprintf(iSQL, sizeof(iSQL), "INSERT INTO Employees (Empno, Name, Email) VALUES(%d, \'%s\', \'%s\')", 1, "chenhd", "chdyczx@live.com");
    m_oMyDb.ExecuteSQL(iSQL, m_oMyDatas.m_oEmployees);

   	snprintf(iSQL, sizeof(iSQL), "INSERT INTO Emails (Sender, Password, Mailhost) VALUES(\'%s\', \'%s\', \'%s\')", "chdyczx@163.com", "123456", "smtp.163.com");
    m_oMyDb.ExecuteSQL(iSQL, m_oMyDatas.m_oEmails);

    snprintf(iSQL, sizeof(iSQL), "INSERT INTO Salarys VALUES(%d, %d, %d, %d, %d, %d, %d, %d, %d, %d, %d, %d)", 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12);
    m_oMyDb.ExecuteSQL(iSQL, m_oMyDatas.m_oSalarys);

    /*
    snprintf(iSQL, sizeof(iSQL), "INSERT INTO Employees (Empno, Name, Email) VALUES(%d, \'%s\', \'%s\')", 2, "chenhd2", "chdyczx@live.com");
    m_oMyDb.ExecuteSQL(iSQL, m_oMyDatas.m_oEmployees);

    snprintf(iSQL, sizeof(iSQL), "INSERT INTO Emails (Sender, Password, Mailhost) VALUES(\'%s\', \'%s\', \'%s\')", "15996228219@163.com", "123456", "smtp.163.com");
    m_oMyDb.ExecuteSQL(iSQL, m_oMyDatas.m_oEmails);

    snprintf(iSQL, sizeof(iSQL), "INSERT INTO Salarys VALUES(%d, %d, %d, %d, %d, %d, %d, %d, %d, %d, %d, %d)", 2, 22, 23, 24, 25, 26, 27, 28, 29, 210, 211, 212);
    m_oMyDb.ExecuteSQL(iSQL, m_oMyDatas.m_oSalarys);

    snprintf(iSQL, sizeof(iSQL), "INSERT INTO Employees (Empno, Name, Email) VALUES(%d, \'%s\', \'%s\')", 3, "chenhd3", "chdyczx@live.com");
    m_oMyDb.ExecuteSQL(iSQL, m_oMyDatas.m_oEmployees);

    snprintf(iSQL, sizeof(iSQL), "INSERT INTO Salarys VALUES(%d, %d, %d, %d, %d, %d, %d, %d, %d, %d, %d, %d)", 3, 32, 33, 34, 35, 36, 37, 38, 39, 310, 311, 312);
    m_oMyDb.ExecuteSQL(iSQL, m_oMyDatas.m_oSalarys);
    */
    return 0;
}

int MyAction::DeleteEmployee(int in_iEmpno)
{
	char iSQL[1024] = {0};
	snprintf(iSQL, sizeof(iSQL), "UPDATE Employees set ValidFlag = 1 where Empno = %d", in_iEmpno);
	m_oMyDb.ExecuteSQL(iSQL, m_oMyDatas.m_oEmployees);
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

    m_oMyDb.ExecuteSQL(iSQL, m_oMyDatas.m_oEmployees);
    /*
    for (Employees::const_iterator it = m_oMyDatas.m_oEmployees.begin(); it != m_oMyDatas.m_oEmployees.end(); ++it)
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
    for (Employees::const_iterator it = m_oMyDatas.m_oEmployees.begin(); it != m_oMyDatas.m_oEmployees.end(); ++it)
    {
        std::cout << "Empno: " << it->get<0>() << 
            ", Name: " << it->get<1>() << 
            ", Email: " << it->get<2>() << std::endl;
    }

    for (Emails::const_iterator it = m_oMyDatas.m_oEmails.begin(); it != m_oMyDatas.m_oEmails.end(); ++it)
    {
        std::cout << "Sender: " << it->get<0>() << 
            ", Password: " << it->get<1>() << 
            ", Mailhost: " << it->get<2>() << std::endl;
    }
    */
    LOG_INFO<< "Send emails begin.";
    MyEmail t_oMyEmail;
    t_oMyEmail.SendEmails(m_oMyDatas);
    LOG_INFO<< "Send emails end.";
    return 0;
}
