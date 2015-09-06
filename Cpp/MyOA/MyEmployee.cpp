#include "MyEmployee.h"

int TEmployee::InsertData()
{
	// insert some rows
    Employee t_oEmployee = 
    {
        11,
        "chenhuidong",
        "chdyczx@live.com"
    };

    m_oStatement << "INSERT INTO Employee VALUES(?, ?, ?)",
    use(t_oEmployee.empno),
    use(t_oEmployee.name),
    use(t_oEmployee.email);

    m_oStatement.execute();
	return 0;
}