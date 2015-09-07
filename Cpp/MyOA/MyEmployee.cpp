#include "MyEmployee.h"

int OPTEmployee::InsertData()
{
    m_oInsertStatement << "INSERT INTO Employee (Empno, Name, Email) VALUES(:Empno, :Name, :Email)",
    	use(m_oEmployees), now;

	return 0;
}

int OPTEmployee::SelectData()
{
	m_oSelectStatement << "SELECT Empno, Name, Email FROM Employee",
		into(m_oEmployees), now;
	
	for (Employees::const_iterator it = m_oEmployees.begin(); it != m_oEmployees.end(); ++it)
	{
		std::cout << "Empno: " << it->get<0>() << 
			", Name: " << it->get<1>() << 
			", Email: " << it->get<2>() << std::endl;
	}
	return 0;
}