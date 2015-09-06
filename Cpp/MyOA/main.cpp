#include "MyData.h"

int main()
{
	MyData mydata;
	mydata.Initialize("employee.db");

	//create table
    *mydata.GetSession() << "CREATE TABLE IF NOT EXISTS Employee (Empno int, Name VARCHAR(30), Email VARCHAR)", now;

    mydata.Uninitialize();
	return 0;
}