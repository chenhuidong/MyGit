#ifndef __MY_LIB_MY_STD_AFX_H_
#define __MY_LIB_MY_STD_AFX_H_

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <fstream>
#include <string.h>
#include <stdarg.h>

#include <string>
#include <vector>
#include <list>
#include <map>
#include <algorithm>

#include <signal.h>
#include <pthread.h>
#include <sys/types.h> 
#include <sys/wait.h> 
#include <sys/stat.h>
#include <sys/statvfs.h>

#include <fcntl.h>
#include <dirent.h>
#include <dirent.h>
#include <regex.h>
#include <time.h>
#include <utime.h>

using namespace std;

#include <errno.h>
extern int errno;

typedef vector<string> VStrings;














/*
//日志设置
#ifdef UNIMPORT_MY_LOG
#else
#define getWorkPath() getenv("WORKPATH")	
//#define getLogPath() getenv("LOGPATH")
#define getLogPath() "/home/chenhuidong/Log"
#define getBinPath() getenv("BINPATH")
#define FLAGS_INFO
#include "MyLog.h"
#endif
//异常
*/
//#include "MyLog.h"
#include "MyEnum.h"
#include "MyException.h"
#include "MyBaseFunc.h"

#endif