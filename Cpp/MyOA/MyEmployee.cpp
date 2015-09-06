#include "MyEmployee.h"

int TEmployee::InsertData(Employee& in_oEmployee)
{
    m_oStatement << "INSERT INTO Employee (Empno, Name, Email) VALUES(?, ?, ?)",
    use(in_oEmployee.empno),
    use(in_oEmployee.name),
    use(in_oEmployee.email);

    m_oStatement.execute();
	return 0;
}

int TEmployee::SelectData()
{
	typedef Poco::Tuple<int, std::string, std::string> Employee1;
	typedef std::vector<Employee1> VEmployee;
	VEmployee t_vecEmployee;

	m_oStatement << "SELECT Empno, Name, Email FROM Employee",
	into(t_vecEmployee),
	now;
	std::cout << "1"<<std::endl;
	for (VEmployee::const_iterator it = t_vecEmployee.begin(); it != t_vecEmployee.end(); ++it)
	{
		std::cout << "Empno: " << it->get<0>() << 
			", Name: " << it->get<1>() << 
			", Email: " << it->get<2>() <<std::endl;
	}
	return 0;
}