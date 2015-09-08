#include "MyData.h"
#include "MyEmployee.h"

int main()
{
    /*
	MyData t_oMyData;
	t_oMyData.Initialize("employee.db");

	//create table
    *t_oMyData.GetSession() << "CREATE TABLE IF NOT EXISTS Employee (Empno int, Name VARCHAR(30), Email VARCHAR, ValidFlag interger(1) default 0)", now;

    OPTEmployee t_oOPTEmployee(t_oMyData.GetSession());

    Employees t_oEmployees;

    t_oEmployees.push_back(Employee(20,"chenhuidong","chdyczx@live.com"));
	t_oOPTEmployee.InsertData(t_oEmployees);
	t_oEmployees.clear();

    t_oOPTEmployee.SelectData(t_oEmployees);
    t_oEmployees.clear();

    int t_iEmpno = 20;
    t_oOPTEmployee.DeleteData(t_iEmpno);
    t_oEmployees.clear();

    t_oOPTEmployee.SelectData(t_oEmployees);
    t_oEmployees.clear();

    SEmployee t_oEmployee;
    t_oEmployee.Name = "chd";
    t_oEmployee.Email = "chdyczx@163.com";
    t_oEmployee.Empno = 4;
    t_oOPTEmployee.UpdateData(t_oEmployee);

    t_oOPTEmployee.SelectData(t_oEmployees);
    t_oEmployees.clear();

    t_oMyData.Uninitialize();
    */

    // parse an XML document and print the generated SAX events
    if (argc < 2)
    {
        std::cout << "usage: " << argv[0] << ": <xmlfile>" << std::endl;
        return 1;
    }
    
    //MyHandler handler;

    SAXParser parser;
    parser.setFeature(XMLReader::FEATURE_NAMESPACES, true);
    parser.setFeature(XMLReader::FEATURE_NAMESPACE_PREFIXES, true);
    //parser.setContentHandler(&handler);
    parser.setProperty(XMLReader::PROPERTY_LEXICAL_HANDLER, static_cast<LexicalHandler*>(&handler));
    
    try
    {
        parser.parse(argv[1]);
    }
    catch (Poco::Exception& e)
    {
        std::cerr << e.displayText() << std::endl;
        return 2;
    }
	return 0;
}

//g++ main.cpp  MyData.cpp MyEmployee.cpp -omain -lPocoDataSQLite