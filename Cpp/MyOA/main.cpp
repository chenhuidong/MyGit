#include "MyData.h"
#include "MyEmployee.h"

int main()
{
	MyData t_oMyData;
	t_oMyData.Initialize("employee.db");

	//create table
    *t_oMyData.GetSession() << "CREATE TABLE IF NOT EXISTS Employee (Empno int, Name VARCHAR(30), Email VARCHAR)", now;

    TEmployee t_oTEmployee(t_oMyData.GetSession());

	// insert some rows
    TEmployee.m_oEmployee.empno = 12;
    TEmployee.m_oEmployee.name = "chenhuidong";
    TEmployee.m_oEmployee.email = "chdyczx@live.com";

	t_oTEmployee.InsertData();

    t_oMyData.Uninitialize();
	return 0;
}

//g++ main.cpp  MyData.cpp MyEmployee.cpp -omain -lPocoDataSQLite