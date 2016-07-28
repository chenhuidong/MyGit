#include "MyException.h"
using namespace MMyLib;

int main()
{
	try
	{
		throw NoRecordException("Test My Exception.");
	}
	catch(TestException& e)
	{
		cout<< e.displayText()<< endl;
	}
	catch(Exception& e)
	{
		cout<< e.displayText()<< endl;
	}
	return 0;
}