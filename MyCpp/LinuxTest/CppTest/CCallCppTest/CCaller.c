#include "CCaller.h"

int main()
{
	printf("result:%d\n", call_cpp_add(2, 3));
	void *pclass = create_myclass();
	printf("result:%d\n", minus_i_i(pclass, 5, 1));
	printf("result:%f\n", minus_d_d(pclass, 5.2, 1.1));
	destory_myclass(pclass);
	pclass = NULL;
	return 0;
}
