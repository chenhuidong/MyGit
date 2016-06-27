#ifndef __MY_LIB_MY_REDIS_H_
#define __MY_LIB_MY_REDIS_H_

#include <redis3m/redis3m.hpp>
#include <iostream>

using namespace redis3m;

namespace MMyLib
{
	connection::ptr_t g_pConn = connection::create();
	reply g_oReply;
};

#endif