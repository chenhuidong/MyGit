#include "Poco/SharedPtr.h"
class A
{
public:
	virtual ~A()
	{}
};
class B: public A
{
};
class C: public A
{
};
int main(int argc, char** argv)
{
	Poco::SharedPtr<A> pA;
	Poco::SharedPtr<B> pB(new B);
	pA = pB;                         // okay, pB is a subclass of pA
	pA = new B;
	// pB = pA;                     // will not compile
	pB = pA.cast<B>();              // okay
	Poco::SharedPtr<C> pC(new C);
	pB = pC.cast<B>();              // pB is null
	return 0;
}

/*
#include "Poco/SharedPtr.h"
#include <string>
#include <iostream>
using Poco::SharedPtr;
int main(int argc, char** argv)
{
	std::string* pString = new std::string("hello, world!");
	Poco::SharedPtr<std::string> p1(pString);                  // rc == 1
	Poco::SharedPtr<std::string> p2(p1);                       // rc == 2
	p2 = 0;                                                    // rc == 1
	// p2 = pString;                                           // BAD BAD BAD: multiple owners -> multiple delete
	p2 = p1;                                                   // rc == 2
	std::string::size_type len = p1->length();                 // dereferencing with ->
	std::cout << *p1 << std::endl;                             // dereferencing with *
	return 0;
}
// rc == 0 -> deleted
*/