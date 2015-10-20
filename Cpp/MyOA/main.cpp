#include "MyAction.h"

int main(int argc, char* argv[])
{
	try
	{
		MyAction t_oMyAction;
		t_oMyAction.InitializeDb("employee.db");
		t_oMyAction.Install();
		//t_oMyAction.InsertData();
		t_oMyAction.SelectData();
		t_oMyAction.SendEmail();
		t_oMyAction.UninitializeDb();
	}
    catch (Poco::NoRecordException& exc)
    {
        std::cerr << exc.displayText() << std::endl;
        t_oMyAction.UninitializeDb();
        return -1;
    }
	return 0;
}
