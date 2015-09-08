#include "MyEmployee.h"

int OPTEmployee::InsertData(Employees &in_oEmployees)
{
    m_oInsertStatement << "INSERT INTO Employee (Empno, Name, Email) VALUES(:Empno, :Name, :Email)",
    	use(in_oEmployees), now;

	return 0;
}

int OPTEmployee::SelectData(Employees &out_oEmployees)
{
	m_oSelectStatement << "SELECT Empno, Name, Email FROM Employee where ValidFlag = 0",
		into(out_oEmployees), now;
	
	for (Employees::const_iterator it = out_oEmployees.begin(); it != out_oEmployees.end(); ++it)
	{
		std::cout << "Empno: " << it->get<0>() << 
			", Name: " << it->get<1>() << 
			", Email: " << it->get<2>() << std::endl;
	}
	return 0;
}

int OPTEmployee::DeleteData(int in_iEmpno)
{
	m_oUpdateStatement << "update Employee set ValidFlag = 1 where Empno = :Empno", use(in_iEmpno), now;
	return 0;
}