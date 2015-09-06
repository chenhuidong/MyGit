#include "MyEmployee.h"

int TEmployee::InsertData(Employee& employee)
{
    m_oStatement << "INSERT INTO Employee VALUES(?, ?, ?)",
    use(employee.empno),
    use(employee.name),
    use(employee.email);

    m_oStatement.execute();
	return 0;
}