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


    /*
    OPTEmployee t_oOPTEmployee(t_oMyData.GetSession());

    Employees t_oEmployees;
    
    t_oEmployees.push_back(Employee(20,"chenhuidong","chdyczx@live.com"));
	t_oOPTEmployee.InsertData(t_oEmployees);
	t_oEmployees.clear();

    int t_iEmpno = 20;
    t_oOPTEmployee.DeleteData(t_iEmpno);
    t_oEmployees.clear();

    SEmployee t_oEmployee;
    t_oEmployee.Name = "chd";
    t_oEmployee.Email = "chdyczx@163.com";
    t_oEmployee.Empno = 4;
    t_oOPTEmployee.UpdateData(t_oEmployee);
    
    t_oOPTEmployee.SelectData(t_oEmployees);
    */