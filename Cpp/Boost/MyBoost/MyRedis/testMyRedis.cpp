#include "MyRedis.h"
using namespace MMyLib;

int main(int argc, char**argv)
{
    IMyRedis t_oMyRedis;
    t_oMyRedis.InitializeRedis();
    redisAsyncCommand(t_oMyRedis.m_pContext, NULL, NULL, "SET key %b", argv[argc-1], strlen(argv[argc-1]));
    redisAsyncCommand(t_oMyRedis.m_pContext, IMyRedis::GetCallback, (char*)"end-1", "GET key");
    event_base_dispatch(t_oMyRedis.m_pBase);
    return 0;
}