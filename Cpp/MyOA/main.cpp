#include "MyData.h"
#include "MyEmployee.h"

int main()
{
	MyData t_oMyData;
	t_oMyData.Initialize("employee.db");

	//create table
    *t_oMyData.GetSession() << "CREATE TABLE IF NOT EXISTS Employee (Empno int, Name VARCHAR(30), Email VARCHAR, ValidFlag interger(1) default 0)", now;
    
    /*
    OPTEmployee t_oOPTEmployee(t_oMyData.GetSession());

    Employees t_oEmployees;
    
    t_oEmployees.push_back(Employee(20,"chenhuidong","chdyczx@live.com"));
	t_oOPTEmployee.InsertData(t_oEmployees);
	t_oEmployees.clear();

    int t_iEmpno = 20;
    t_oOPTEmployee.DeleteData(t_iEmpno);
    t_oEmployees.clear();

    SEmployee t_oEmployee;
    t_oEmployee.Name = "chd";
    t_oEmployee.Email = "chdyczx@163.com";
    t_oEmployee.Empno = 4;
    t_oOPTEmployee.UpdateData(t_oEmployee);
    
    t_oOPTEmployee.SelectData(t_oEmployees);
    */
    Employees t_inEmployees;
    Employees t_outEmployees;

    /*
    t_oEmployees.push_back(Employee(20,"chenhuidong","chdyczx@live.com"));
    t_oMyData.ExecuteSQL("INSERT INTO Employee (Empno, Name, Email) VALUES(:Empno, :Name, :Email)", t_inEmployees, t_outEmployees);
    t_oEmployees.clear();
    */

    t_oMyData.ExecuteSQL("SELECT Empno, Name, Email FROM Employee where ValidFlag = 0", t_inEmployees, t_outEmployees);
    for (Employees::const_iterator it = t_outEmployees.begin(); it != t_outEmployees.end(); ++it)
    {
        std::cout << "Empno: " << it->get<0>() << 
            ", Name: " << it->get<1>() << 
            ", Email: " << it->get<2>() << std::endl;
    }
    t_inEmployees.clear();
    t_outEmployees.clear();

    t_oMyData.Uninitialize();

	return 0;
}

//g++ main.cpp  MyData.cpp -omain -lPocoDataSQLite
