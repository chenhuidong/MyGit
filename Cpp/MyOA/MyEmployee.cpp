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
	std::vector<Employee> t_vecEmployee;

	m_oStatement << "SELECT Empno, Name, Email FROM Employee",
	into(t_vecEmployee),
	now;
	return 0;
}