#include "MyData.h"
#include "MyEmployee.h"

int main()
{
	MyData t_oMyData;
	t_oMyData.Initialize("employee.db");

	//create table
    *t_oMyData.GetSession() << "CREATE TABLE IF NOT EXISTS Employee (Empno int primary key, Name VARCHAR(30), Email VARCHAR, ValidFlag interger(1) default 0)", now;

    TEmployee t_oTEmployee(t_oMyData.GetSession());

    // insert some rows
    Employee t_oEmployee = 
    {
    	15,
    	"chenhuidong",
    	"chdyczx@live.com"
    };

	//t_oTEmployee.InsertData(t_oEmployee);
    t_oTEmployee.SelectData();

    t_oMyData.Uninitialize();
	return 0;
}

//g++ main.cpp  MyData.cpp MyEmployee.cpp -omain -lPocoDataSQLite