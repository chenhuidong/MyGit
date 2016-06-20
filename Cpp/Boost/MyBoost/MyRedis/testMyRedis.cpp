#include "MyStdAfx.h"
using namespace MMyLib;

int main()
{
    IMyRedis t_oMyRedis;
    t_oMyRedis.InitializeRedis();
    redisAsyncCommand(t_oMyRedis.m_pContext, NULL, NULL, "SET key %b", argv[argc-1], strlen(argv[argc-1]));
    redisAsyncCommand(t_oMyRedis.m_pContext, GetCallback, (char*)"end-1", "GET key");
    return 0;
}