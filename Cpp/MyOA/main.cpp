#include "MyData.h"

int main()
{
	MyData mydata;
	mydata.Initialize("employee.db");

	//create table
    *mydata.m_pSession << "CREATE TABLE IF NOT EXISTS Employee (Empno int, Name VARCHAR(30), Email VARCHAR)", now;


	return 0;
}