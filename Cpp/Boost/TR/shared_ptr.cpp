#include <boost/smart_ptr.hpp>
#include <iostream>
#include <string>
using namespace boost;
using namespace std;

int main()
{
	shared_ptr<int> spi(new int);
	assert(spi);
	*spi = 253;
	cout<< *spi<< endl;
	
	shared_ptr<string> sps(new string("smart"));
	assert(sps->size() == 5);
	cout<< sps->size()<< endl;
	return 0;
}
