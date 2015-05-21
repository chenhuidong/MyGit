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
//GLog
#include <glog/logging.h>
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

//Glog
#define LOG_INFO LOG(INFO)
#define LOG_WARN LOG(WARNING)
#define LOG_ERROR LOG(ERROR)
#define LOG_FATAL LOG(FATAL)

#define INITIALIZE_LOG() INITIALIZE_LOG1(argv[0])
#define INITIALIZE_LOG1(link)\
{\
	google::InitGoogleLogging(link);\
	google::SetStderrLogging(google::GLOG_FATAL);\
	FLAGS_logtostderr = 0;\
	FLAGS_servitysinglelog = true;\
	string t_strLogPath = getenv("LOGPATH");\
	FLAGS_log_dir = t_strLogPath;\
	google::SetLogDestination(google::INFO, (string(FLAGS_log_dir)+"/"+link+".info.").c_str());\
	google::SetLogDestination(google::WARNING, (string(FLAGS_log_dir)+"/"+link+".warning.").c_str());\
	google::SetLogDestination(google::ERROR, (string(FLAGS_log_dir)+"/"+link+".error.").c_str());\
	google::SetLogDestination(google::FATAL, (string(FLAGS_log_dir)+"/"+link+".fatal.").c_str());\
}

/*	#ifdef DEBUG_MODE\
        google::SetStderrLogging(google::GLOG_INFO); \
    #else\
        google::SetStderrLogging(google::GLOG_FATAL);\
    #endif\
    */
//FLAGS_servitysinglelog = true;// 用来按照等级区分log文件
//google::SetStderrLogging(google::GLOG_INFO);//设置级别高于 google::INFO 的日志同时输出到屏幕
//FLAGS_colorlogtostderr = true; //设置输出到屏幕的日志显示相应颜色
//FLAGS_logbufsecs = 0; //缓冲日志输出，默认为30秒，此处改为立即输出
//FLAGS_max_log_size = 100; //最大日志大小为 100MB
//FLAGS_stop_logging_if_full_disk = true; //当磁盘被写满时，停止日志输出
//google::SetLogFilenameExtension("91_"); //设置文件名扩展，如平台？或其它需要区分的信息
//google::InstallFailureSignalHandler(); //捕捉 core dumped (linux)
//google::InstallFailureWriter(&Log); //默认捕捉 SIGSEGV 信号信息输出会输出到 stderr (linux)
#endif