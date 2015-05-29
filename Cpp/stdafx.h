#ifndef __STD_AFX_H
#define __STD_AFX_H

#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <iostream>
#include <list>
#include <vector>
#include <map>
#include <set>
#include <sys/types.h>
#include <string.h>
#include <string>
using namespace std;

#define  ___ANONYMOUS1(var, line)  var##line
#define  __ANONYMOUS0(line)  ___ANONYMOUS1(_anonymous, line)
#define  ANONYMOUS()  __ANONYMOUS0(__LINE__)
#define ForEachOf(x, y, z) \
y::iterator ANONYMOUS() = z.end(); \
for(y::iterator x = z.begin();x != ANONYMOUS();++x)
#define ForEachOf_Const(x, y, z) \
	y::const_iterator ANONYMOUS() = z.end(); \
for(y::const_iterator x = z.begin();x != ANONYMOUS();++x)

#define ForEachOf_Reverse(x, y, z) \
	y::reverse_iterator ANONYMOUS() = z.rend(); \
for(y::reverse_iterator x = z.rbegin();x != ANONYMOUS();++x)

#define ForEachOf_Reverse_Const(x, y, z) \
	y::const_reverse_iterator ANONYMOUS() = z.rend(); \
for(y::const_reverse_iterator x = z.rbegin();x != ANONYMOUS();++x)

typedef int8_t	int8;
typedef int16_t int16;
typedef int32_t int32;
typedef int64_t int64;

typedef u_int8_t  uint8;
typedef u_int16_t uint16;
typedef u_int32_t uint32;
typedef u_int64_t uint64;

//typedef wchar_t wchar;

typedef list<int> IntList;
typedef vector<int> IntVec;

#endif