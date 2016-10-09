#ifndef __MY_LIB_MY_REDIS_H_
#define __MY_LIB_MY_REDIS_H_

#include "MyStdAfx.h"
#include <redis3m/redis3m.hpp>
#include <iostream>

using namespace redis3m;

namespace MMyLib
{
	static connection::ptr_t g_pRedisConn = connection::create(REDISIP, REDISPORT);
};

#endif