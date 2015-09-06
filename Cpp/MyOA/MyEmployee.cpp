#include "MyEmployee.h"

int TEmployee::InsertData()
{
	// insert some rows
    m_oEmployee.empno = 11;
    m_oEmployee.name = "chenhuidong";
    m_oEmployee.email = "chdyczx@live.com";

    m_oStatement << "INSERT INTO Employee VALUES(?, ?, ?)",
    use(m_oEmployee.empno),
    use(m_oEmployee.name),
    use(m_oEmployee.email);

    m_oStatement.execute();
	return 0;
}