#include "MyData.h"

int main()
{
	MyData t_oMyData;
	t_oMyData.Initialize("employee.db");

	//create table
    *t_oMyData.GetSession() << "CREATE TABLE IF NOT EXISTS Employee (Empno int, Name VARCHAR(30), Email VARCHAR)", now;

    TEmployee t_oTEmployee(t_oMyData.GetSession());

    t_oMyData.Uninitialize();
	return 0;
}