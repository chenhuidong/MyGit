#include "MyException.h"

int main()
{
	try
	{
		throw Poco::NoRecordException("Test My Exception.");
	}
	catch(Poco::TestException& e)
	{
		cout<< e.displayText()<< endl;
	}
	catch(Exception& e)
	{
		cout<< e.displayText()<< endl;
	}
	return 0;
}