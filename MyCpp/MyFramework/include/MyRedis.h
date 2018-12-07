#ifndef __MY_LIB_MY_REDIS_H_
#define __MY_LIB_MY_REDIS_H_

#include "MyStdAfx.h"
#include <iostream>

#define ACL_REDIS

#ifndef ACL_REDIS
	#include <redis3m/redis3m.hpp>
	using namespace redis3m;
#else
	#include "lib_acl_cpp/include/acl_cpp/lib_acl.hpp"
#endif

namespace MMyLib
{
#ifndef ACL_REDIS
	const connection::ptr_t g_pRedisConn = connection::create(REDISIP, REDISPORT);
#else
	class IMyRedis
	{
	public:
		IMyRedis();
		virtual ~IMyRedis();
	public:
		int InitMyRedis(string in_sAddr);
	public:
		acl::redis_string m_oMyRedisString;
		acl::redis_hash	  m_oMyRedisHash;
		acl::redis_client_cluster m_oCluster;
	};
#endif	
};

#endif