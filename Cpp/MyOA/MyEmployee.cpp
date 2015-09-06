#include "MyEmployee.h"

int TEmployee::InsertData()
{
    m_oStatement << "INSERT INTO Employee VALUES(?, ?, ?)",
    use(m_oEmployee.empno),
    use(m_oEmployee.name),
    use(m_oEmployee.email);

    m_oStatement.execute();
	return 0;
}