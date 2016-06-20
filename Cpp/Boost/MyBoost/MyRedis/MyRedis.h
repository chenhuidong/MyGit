#ifndef __MY_LIB_MY_REDIS_H_
#define __MY_LIB_MY_REDIS_H_

#include <hiredis.h>
#include <async.h>
#include <adapters/libevent.h>

namespace MMyLib
{
	class IMyRedis
	{
	public:
		IMyRedis(){}
		virtual ~IMyRedis(){}
		int InitializeRedis();
	private:
		virtual void GetCallback(redisAsyncContext *c, void *r, void *privdata) = 0;
		virtual void ConnectCallback(const redisAsyncContext *c, int status) = 0;
		virtual void DisconnectCallback(const redisAsyncContext *c, int status) = 0;
	};

	class MyRedis: public IMyRedis
	{
	public:
		MyRedis(){}
		virtual ~MyRedis(){}
	private:
		void GetCallback(redisAsyncContext *c, void *r, void *privdata);
		void ConnectCallback(const redisAsyncContext *c, int status);
		void DisconnectCallback(const redisAsyncContext *c, int status);
	};
};
 

#endif