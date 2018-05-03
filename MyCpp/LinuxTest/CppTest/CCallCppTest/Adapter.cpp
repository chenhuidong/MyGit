#include "Adapter.h"

int call_cpp_add(int a, int b)
{
	return add(a, b);
}

void* create_myclass()
{
	return new MyClass();
}

void destory_myclass(void* pthis)
{
	delete static_cast<MyClass *>(pthis);
}

int minus_i_i(void* pthis, int a, int b)
{
	return static_cast<MyClass *>(pthis)->minus(a, b);
}

double minus_d_d(void* pthis, double a, double b)
{
	return static_cast<MyClass *>(pthis)->minus(a, b);
}