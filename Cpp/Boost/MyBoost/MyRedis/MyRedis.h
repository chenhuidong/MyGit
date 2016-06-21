#ifndef __MY_LIB_MY_REDIS_H_
#define __MY_LIB_MY_REDIS_H_

#include "MyStdAfx.h"
#include <hiredis.h>
#include <async.h>
#include <adapters/libevent.h>

namespace MMyLib
{
	#define MY_REDIS_IP "127.0.0.1"
	#define MY_REDIS_PORT 6379

	class IMyRedis
	{
	public:
		IMyRedis(){}
		virtual ~IMyRedis(){}
	private:
		int InitializeRedis();
		int DisconnectRedis();
		int DispatchRedis();
		static void GetCallback(redisAsyncContext *c, void *r, void *privdata);
	private:
		static void ConnectCallback(const redisAsyncContext *c, int status);
		static void DisconnectCallback(const redisAsyncContext *c, int status);
	public:
		struct event_base *m_pBase;
		redisAsyncContext *m_pContext;
	};
};


#endif