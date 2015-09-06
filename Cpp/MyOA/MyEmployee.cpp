#include "MyEmployee.h"

int TEmployee::InsertData(Employee& in_oEmployee)
{
    m_oStatement << "INSERT INTO Employee VALUES(?, ?, ?)",
    use(in_oEmployee.empno),
    use(in_oEmployee.name),
    use(in_oEmployee.email);

    m_oStatement.execute();
	return 0;
}