#ifndef __MY_LIB_MY_BASE_FUNC_H_
#define __MY_LIB_MY_BASE_FUNC_H_

#include "MyStdAfx.h"

namespace MMyLib
{
	//iterator define
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

	string 	itoa(int32	i);
	string 	itoa(int64	i);
	int64 	atol64(const char * szStr);
	string 	toUpper(string& in_str);
	string 	toLower(string&	in_str);
};

#endif