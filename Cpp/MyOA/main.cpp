#include "../stdafx.h"
#include "MyData.h"
#include "MyException.h"
#include "MyAction.h"


int main(int argc, char* argv[])
{
	MyAction t_oMyAction;
	t_oMyAction.InitializeDb("employee.db");
	t_oMyAction.Install();
	t_oMyAction.SelectData();
	t_oMyAction.UninitializeDb();
	return 0;
}
