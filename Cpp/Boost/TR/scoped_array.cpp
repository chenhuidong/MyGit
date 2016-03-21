#include <boost/smart_ptr.hpp>
#include <iostream>
#include <string>
using namespace boost;
using namespace std;

int main()
{
	scoped_array<int> sa1(new int[100]);
	sa1[0] = 10;
	cout<< sa1[0]<< endl;

	int *arr = new int[100];
	scoped_array<int> sa(arr);

	fill_n(&sa[0], 100, 5);

	sa[10] = sa[20] + sa[30];

	cout<< sa[10]<< " "<< sa[20]<< " "<< sa[30]<<endl;
	return 0;
}

//g++ scoped_ptr.cpp -omain -lboost_math_tr1
