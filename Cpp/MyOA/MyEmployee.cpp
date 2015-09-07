#include "MyEmployee.h"

int OPTEmployee::InsertData()
{
    m_oInsertStatement << "INSERT INTO Employee (Empno, Name, Email, ValidFlag) VALUES(:Empno, :Name, :Email, :ValidFlag)",
    	use(m_oEmployees), now;

	return 0;
}

int OPTEmployee::SelectData()
{
	//std::cout<< "1"<< std::endl;
	//m_oSelectStatement << "SELECT Empno, Name, Email, ValidFlag FROM Employee",
	//	into(m_oEmployees), now;
	//m_oSelectStatement << "SELECT Empno, Name, Email, ValidFlag FROM Employee",
	//	into(m_oEmployees), now;
	//std::cout<< "2"<< std::endl;
	/*for (Employees::const_iterator it = m_oEmployees.begin(); it != m_oEmployees.end(); ++it)
	{
		std::cout << "Empno: " << it->get<0>() << 
			", Name: " << it->get<1>() << 
			", Email: " << it->get<2>() << 
			", ValidFlag: " << it->get<3>() <<std::endl;
	}*/

	struct Employee
	{
		int			empno;
		std::string name;
		std::string email;
		int 		validflag;
	} person;

    m_oSelectStatement << "SELECT Empno, Name, Email, ValidFlag FROM Employee",
        into(person.empno),
        into(person.name),
        into(person.email),
        into(person.validflag),
        range(0, 1); //  iterate over result set one row at a time

    while (!m_oSelectStatement.done())
    {
        m_oSelectStatement.execute();
        std::cout << person.empno << " " << person.name << " " << person.email << std::endl;
    }
	return 0;
}