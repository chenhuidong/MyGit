#include "MyAction.h"

int MyAction::InitializeDb(const char* in_sDbName)
{
	m_oMyData.Initialize(in_sDbName);
	return 0;
}

int MyAction::Install()
{
	//create table
	*m_oMyData.GetSession() << "CREATE TABLE IF NOT EXISTS Employee (Empno int, Name VARCHAR(256), Email VARCHAR(256), ValidFlag interger(1) default 0)", now;
    *m_oMyData.GetSession() << "CREATE TABLE IF NOT EXISTS Email (Sender VARCHAR(256) primary key, Password VARCHAR(256), Mailhost VARCHAR(256))", now;
    return 0;
}

int MyAction::SelectData()
{
	m_oMyData.ExecuteSQL("SELECT Empno, Name, Email FROM Employee where ValidFlag = 0", m_oEmployees);
    /*
	for (Employees::const_iterator it = m_oEmployees.begin(); it != m_oEmployees.end(); ++it)
    {
        std::cout << "Empno: " << it->get<0>() << 
            ", Name: " << it->get<1>() << 
            ", Email: " << it->get<2>() << std::endl;
    }
    */
    if(m_oEmployees.empty())
    {
    	throw Poco::NoRecordException("Employees no record.");
    }

    m_oMyData.ExecuteSQL("SELECT * FROM Email", m_oEmails);
    /*
    for (Emails::const_iterator it = m_oEmails.begin(); it != m_oEmails.end(); ++it)
    {
        std::cout << "Sender: " << it->get<0>() << 
            ", Password: " << it->get<1>() << 
            ", Mailhost: " << it->get<2>() << std::endl;
    }
    */
    if(m_oEmails.empty())
    {
    	throw Poco::NoRecordException("Email no record.");
    }
    return 0;
}

int MyAction::UninitializeDb()
{
	m_oMyData.Uninitialize();
	return 0;
}

int MyAction::InsertData()
{
	char iSQL[1024] = {0};
	snprintf(iSQL, sizeof(iSQL), "INSERT INTO Employee (Empno, Name, Email) VALUES(%d, \'%s\', \'%s\')", 2, "cccc", "fdsfs@163.com");
    m_oMyData.ExecuteSQL(iSQL, m_oEmployees);

   	snprintf(iSQL, sizeof(iSQL), "INSERT INTO Email (Sender, Password, Mailhost) VALUES(%d, \'%s\', \'%s\')", "chdyczx@live.com", "cccc", "smtp@163.com");
    m_oMyData.ExecuteSQL(iSQL, m_oEmails);
    return 0;
}

int MyAction::DeleteEmployee(int in_iEmpno)
{
	char iSQL[1024] = {0};
	snprintf(iSQL, sizeof(iSQL), "UPDATE Employee set ValidFlag = 1 where Empno = %d", in_iEmpno);
	m_oMyData.ExecuteSQL(iSQL, m_oEmployees);
	return 0;
}

int MyAction::UpdateEmployee()
{
    return 0;
}

int MyAction::SelectEmployee(int in_iEmpno)
{
    char iSQL[1024] = {0};
    snprintf(iSQL, sizeof(iSQL), "SELECT Empno, Name, Email FROM Employee where ValidFlag = 0 and Empno = %d", in_iEmpno);

    m_oMyData.ExecuteSQL(iSQL, m_oEmployees);
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

int MyAction::CreateEmail()
{
    std::ofstream ostr("/mnt/home2/51linux_LxomB0aQ/Log/1.log");
    ostr << "'hello world'" << std::endl;
    /*
    ostr << "   <div class=\"form-group col-sm-6\">
        <label class=\"col-sm-4 control-label\" for=\"field_{$data.name}\">{$data.name}</label>
        <div class=\"col-sm-8\">
            {:W('UserDefineControl/edit',array($data))}
        </div>
    </div>" << std::endl;
    */
    ostr.close();
    return 0;
}

int MyAction::CreateEmails()
{
    CreateEmail();
    return 0;
}

int MyAction::SendEmail()
{   /*
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
    
    return 0;
}
