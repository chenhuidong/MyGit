#include "MyRedis.h"

int MMyLib::IMyRedis::InitializeRedis()
{
	signal(SIGPIPE, SIG_IGN);
	m_pBase = event_base_new();
	m_pContext = redisAsyncConnect("127.0.0.1", 6379);

	if (m_pContext->err) 
	{
		printf("Error: %s\n", m_pContext->errstr);
		return 1;
	}

	redisLibeventAttach(m_pContext, m_pBase);
    redisAsyncSetConnectCallback(m_pContext, IMyRedis::ConnectCallback);
    redisAsyncSetDisconnectCallback(m_pContext, IMyRedis::DisconnectCallback);
    event_base_dispatch(m_pBase);
}

static void MMyLib::IMyRedis::GetCallback(redisAsyncContext *c, void *r, void *privdata)
{

}

static void MMyLib::IMyRedis::ConnectCallback(const redisAsyncContext *c, int status)
{
    if (status != REDIS_OK) 
    {
        printf("Error: %s\n", c->errstr);
        return;
    }
    printf("Connected...\n");
}

static void MMyLib::IMyRedis::DisconnectCallback(const redisAsyncContext *c, int status)
{
	if (status != REDIS_OK) 
	{
        printf("Error: %s\n", c->errstr);
        return;
    }
    printf("Disconnected...\n");
}