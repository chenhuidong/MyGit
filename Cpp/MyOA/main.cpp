#include "MyData.h"

int main()
{
	MyData mysqlite;
	mysqlite.Initialize("employee.db");

	//create table
    session << "CREATE TABLE Employee (empno int, Name VARCHAR(30), email VARCHAR)", now;

    
	return 0;
}