#include "Poco/AutoPtr.h"
#include "Poco/RefCountedObject.h"

class A: public Poco::RefCountedObject
{
};

int main(int argc, char** argv)
{
     Poco::AutoPtr<A> p1(new A);
     A* pA = p1;
     // Poco::AutoPtr<A> p2(pA); // BAD! p2 assumes sole ownership
     Poco::AutoPtr<A> p2(pA, true); // Okay: p2 shares ownership with p1
     Poco::AutoPtr<A> p3;
     // p3 = pA; // BAD! p3 assumes sole ownership
     p3.assign(pA, true); // Okay: p3 shares ownership with p1
     return 0;
}