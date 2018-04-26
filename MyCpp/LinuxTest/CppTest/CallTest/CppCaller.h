#ifndef _CPP_CALLER_H_
#define _CPP_CALLER_H_

#include <iostream>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <string>
using namespace std;

//1
/*
#ifdef __cplusplus
extern "C" {
#endif

#include "CCalled.h"

int add(int a,int b);

#ifdef __cplusplus
}
#endif

//extern "C" int add(int a,int b);
*/

//2
#ifdef __cplusplus
extern "C" {
#endif
#include "CCalled.h"
#ifdef __cplusplus
}
#endif

#endif