#include "MyEmployee.h"

int OPTEmployee::InsertData()
{
	std::cout<< "1"<< std::endl;
    m_oInsertStatement << "INSERT INTO Employee (Empno, Name, Email, ValidFlag) VALUES(:Empno, :Name, :Email, :ValidFlag)",
    	use(m_oEmployees), now;

    //m_oInsertStatement.execute();
	return 0;
}

int OPTEmployee::SelectData()
{
	std::cout<< "1"<< std::endl;
	m_oSelectStatement << "SELECT Empno, Name, Email, ValidFlag FROM Employee",
		into(m_oEmployees),now;
	std::cout<< "2"<< std::endl;
	for (Employees::const_iterator it = m_oEmployees.begin(); it != m_oEmployees.end(); ++it)
	{
		std::cout << "Empno: " << it->get<0>() << 
			", Name: " << it->get<1>() << 
			", Email: " << it->get<2>() << 
			", ValidFlag: " << it->get<3>() <<std::endl;
	}
	return 0;
}