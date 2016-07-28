#include <boost/pool/object_pool.hpp>
#include <iostream>
using namespace boost;
using namespace std;

struct demo_class
{
public:
	int a, b, c;
	demo_class(int x=1, int y=2, int z=3):a(x), b(y), c(z){}
};

int main()
{
	object_pool<demo_class> pl;

	demo_class *p = pl.malloc();
	assert(pl.is_from(p));

	assert(p->a!=1 || p->b!=2 || p->c!=3);

	p=pl.construct(7, 8, 9);

	assert(p->a == 7);

	object_pool<string> pls;

	for(int i=0; i<100; ++i)
	{
		string *ps = pls.construct("hello object_pool");
		cout<< *ps<< endl;	
	}
	return 0;
}

//g++ object_pool.cpp -oobject_pool -lboost_system
