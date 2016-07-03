#ifndef __MY_LIB_MY_STD_AFX_H_
#define __MY_LIB_MY_STD_AFX_H_

#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <iostream>
#include <fstream>
#include <list>
#include <vector>
#include <map>
#include <set>
#include <algorithm>
#include <string.h>
#include <string>
#include <signal.h>
using namespace std;

//日志设置
#define getWorkPath() getenv("WORKPATH")	
#define getLogPath() getenv("LOGPATH")
#define FLAGS_INFO
#include "MyLog.h"

//异常
#include "MyException.h"

#define BUFFSIZE 4096

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



#endif