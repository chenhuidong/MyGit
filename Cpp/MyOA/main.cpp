#include "MyData.h"
#include "MyEmployee.h"

int main()
{
	//MyData t_oMyData;
	//t_oMyData.Initialize("employee.db");

	//create table
    //*t_oMyData.GetSession() << "CREATE TABLE IF NOT EXISTS Employee (Empno int primary key, Name VARCHAR(30), Email VARCHAR, ValidFlag interger(1) default 0)", now;

    //OPTEmployee t_oOPTEmployee(t_oMyData.GetSession());


    //t_oOPTEmployee.m_oEmployees.push_back(Employee(20,"chenhuidong","chdyczx@live.com", 0));
	//t_oOPTEmployee.InsertData();
	//t_oOPTEmployee.m_oEmployees.clear();

    //t_oOPTEmployee.SelectData();

    //t_oMyData.Uninitialize();
    //
    Poco::Data::SQLite::Connector::registerConnector();
    Session session("SQLite", "employee.db");
    session << "CREATE TABLE Person (Name VARCHAR(30), Address VARCHAR, Age INTEGER(3))", now;

	struct Person
	{
	    std::string name;
	    std::string address;
	    int         age;
	} person;

	Statement select(session);
    select << "SELECT Name, Address, Age FROM Person",
        into(person.name),
        into(person.address),
        into(person.age),
        range(0, 1); //  iterate over result set one row at a time

    while (!select.done())
    {
        select.execute();
        std::cout << person.name << " " << person.address << " " << person.age << std::endl;
    }
	return 0;
}

//g++ main.cpp  MyData.cpp MyEmployee.cpp -omain -lPocoDataSQLite