#include <boost/smart_ptr.hpp>
#include <iostream>
#include <string>
using namespace boost;
using namespace std;

int main()
{
	unique_ptr<int> up(new int);
	assert(up);
	*up = 10;
	cout<< *up<< endl;
	up.reset();
	assert(!up);
	return 0;
}