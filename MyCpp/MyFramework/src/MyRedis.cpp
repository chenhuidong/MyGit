#include "MyRedis.h"

#ifndef ACL_REDIS
#else
	MMyLib::IMyRedis::IMyRedis()
	{
	}

	MMyLib::IMyRedis::~IMyRedis()
	{
	}

	int MMyLib::IMyRedis::InitMyRedis(string in_sAddr)
	{
		int  conn_timeout = 10, rw_timeout = 10, max_threads = 10;
		acl::acl_cpp_init();

		//acl::redis_client_cluster cluster;
		m_oCluster.set(in_sAddr.c_str(), 100, conn_timeout, rw_timeout);

		//acl::redis_client client(in_sAddr.c_str(), conn_timeout, rw_timeout);

		m_oMyRedisString.set_cluster(&m_oCluster,max_threads);
		m_oMyRedisHash.set_cluster(&m_oCluster,max_threads);
	}
#endif
