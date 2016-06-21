#include "MyRedis.h"
using namespace MMyLib;

int main(int argc, char**argv)
{
    IMyRedis t_oMyRedis;
    t_oMyRedis.InitializeRedis();
    string i;
    cin>>i;
    while(i.strlen())
    {
    	redisAsyncCommand(t_oMyRedis.m_pContext, NULL, NULL, "SET key %s", i);
    	redisAsyncCommand(t_oMyRedis.m_pContext, IMyRedis::GetCallback, (char*)"end-1", "GET key");
    	cin>>i;
	}
	t_oMyRedis.DisconnectRedis();
	t_oMyRedis.DispatchRedis();
    return 0;
}