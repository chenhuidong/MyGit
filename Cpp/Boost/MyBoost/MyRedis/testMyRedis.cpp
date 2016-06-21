#include "MyRedis.h"
using namespace MMyLib;

int main(int argc, char**argv)
{
    IMyRedis t_oMyRedis;
    t_oMyRedis.InitializeRedis();
    int i;
    cin>>i;
    while(i!=0)
    {
    	redisAsyncCommand(t_oMyRedis.m_pContext, NULL, NULL, "SET key %d", i);
    	redisAsyncCommand(t_oMyRedis.m_pContext, IMyRedis::GetCallback, (char*)"end-1", "GET key");
    	t_oMyRedis.DispatchRedis();
    	cin>>i;
	}
    return 0;
}