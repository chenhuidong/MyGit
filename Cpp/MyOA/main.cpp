#include "MyData.h"

int main()
{
	MyData mydata;
	mydata.Initialize("employee.db");

	//create table
    *mydata.m_pSession << "CREATE TABLE Employee (empno int, Name VARCHAR(30), email VARCHAR)", now;


	return 0;
}