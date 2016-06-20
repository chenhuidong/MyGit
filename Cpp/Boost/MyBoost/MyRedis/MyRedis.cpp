#include "MyRedis.h"

int MMyLib::MyRedis::InitializeRedis()
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
    redisAsyncSetConnectCallback(m_pContext, ConnectCallback);
    redisAsyncSetDisconnectCallback(m_pContext, DisconnectCallback);
    event_base_dispatch(m_pBase);
}

void MMyLib::MyRedis::GetCallback(redisAsyncContext *c, void *r, void *privdata)
{
	
}

void MMyLib::MyRedis::ConnectCallback(const redisAsyncContext *c, int status)
{
    if (status != REDIS_OK) 
    {
        printf("Error: %s\n", c->errstr);
        return;
    }
    printf("Connected...\n");
}

void MMyLib::MyRedis::DisconnectCallback(const redisAsyncContext *c, int status)
{
	if (status != REDIS_OK) 
	{
        printf("Error: %s\n", c->errstr);
        return;
    }
    printf("Disconnected...\n");
}