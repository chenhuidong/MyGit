#ifndef _C_CALLED_H_
#define _C_CALLED_H_

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
//1
//int add(int a, int b);

//2

#ifdef __cplusplus
extern "C" {
#endif
int add(int a, int b);
#ifdef __cplusplus
}
#endif

#endif