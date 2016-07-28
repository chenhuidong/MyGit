#include <iostream>
#include <memory>
using namespace std;

class A
{
public:
	A(){cout<< "A"<< endl;}
	~A(){cout<< "~A"<< endl;}
};

int main()
{
	auto_ptr<A> p(new A);
	return 0;
}