/*#include "Poco/AutoPtr.h"
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
}*/

#include "Poco/AutoPtr.h"
using Poco::AutoPtr;
class RCO
{
public:
       RCO(): _rc(1)
       {
       }

       void duplicate()
       {
              ++_rc;                                                    // Warning: not thread safe!
       }

       void release()
       {
              if (--_rc == 0) delete this;                             // Warning: not thread safe!
       }

private:
       int _rc;
};

int main(int argc, char** argv)
{
       RCO* pNew = new RCO;                                    // _rc == 1
       AutoPtr<RCO> p1(pNew);                                  // _rc == 1
       AutoPtr<RCO> p2(p1);                                    // _rc == 2
       AutoPtr<RCO> p3(pNew, true);                            // _rc == 3
       p2 = 0;                                                 // _rc == 2
       p3 = 0;                                                 // _rc == 1
       RCO* pRCO = p1;                                         // _rc == 1
       p1 = 0;                                                 // _rc == 0 -> deleted

       // pRCO and pNew now invalid!
       p1 = new RCO;                                           // _rc == 1
       return 0;
}
                                                               // _rc == 0 -> deleted