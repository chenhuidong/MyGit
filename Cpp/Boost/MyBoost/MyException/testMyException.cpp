#include "MyException.h"

int main()
{
	try
	{
		throw Poco::NoRecordException("Test My Exception.");
	}
	catch(Poco::TestException& e)
	{
		cout<< e.what()<< endl;
	}
	catch(Exception& e)
	{
		cout<< e.what()<< endl;
	}
	return 0;
}