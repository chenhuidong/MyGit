#include "MyEmployee.h"

int OPTEmployee::InsertData(Employees &in_oEmployees)
{
	Statement t_oInsertStatement(*m_pSession);
    t_oInsertStatement << "INSERT INTO Employee (Empno, Name, Email) VALUES(:Empno, :Name, :Email)",
    	use(in_oEmployees), now;

	return 0;
}

int OPTEmployee::SelectData(Employees &out_oEmployees)
{
	Statement t_oSelectStatement(*m_pSession);
	t_oSelectStatement << "SELECT Empno, Name, Email FROM Employee where ValidFlag = 0",
		into(out_oEmployees), now;
	/*
	for (Employees::const_iterator it = out_oEmployees.begin(); it != out_oEmployees.end(); ++it)
	{
		std::cout << "Empno: " << it->get<0>() << 
			", Name: " << it->get<1>() << 
			", Email: " << it->get<2>() << std::endl;
	}
	*/
	return 0;
}

int OPTEmployee::DeleteData(int in_iEmpno)
{
	Statement t_oUpdateStatement(*m_pSession);
	t_oUpdateStatement << "update Employee set ValidFlag = 1 where Empno = :Empno", use(in_iEmpno), now;
	return 0;
}

int OPTEmployee::UpdateData(SEmployee &in_oSEmployee)
{
	Statement t_oUpdateStatement(*m_pSession);
    t_oUpdateStatement << "update Employee set Name=:Name, Email=:Email where Empno=:Empno",
    	use(in_oSEmployee.Name),
    	use(in_oSEmployee.Email),
    	use(in_oSEmployee.Empno),
    	now;

	return 0;
}