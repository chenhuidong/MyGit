#include <boost/smart_ptr.hpp>
#include <iostream>
#include <string>
using namespace boost;
using namespace std;

int main()
{
	scoped_ptr<string> sp(new string("text"));
	cout<< *sp<< endl;
	cout<< sp->size()<< endl;

	if(sp)
	{

	}
	return 0;
}

//g++ scoped_ptr.cpp -omain -lboost_math_tr1
