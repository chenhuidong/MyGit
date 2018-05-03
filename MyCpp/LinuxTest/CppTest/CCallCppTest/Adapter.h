#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <iostream>
#include "CppCalled.h"
using namespace std;

#ifdef __cplusplus
extern "C"
{
#endif

int call_cpp_add(int a, int b);
void* create_myclass();
void destory_myclass(void* pthis); 
int minus_i_i(void* pthis, int a, int b);
double minus_d_d(void* pthis, double a, double b);

#ifdef __cplusplus
}
#endif