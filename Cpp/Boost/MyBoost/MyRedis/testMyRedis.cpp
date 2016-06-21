#include "MyRedis.h"
using namespace MMyLib;

int main(int argc, char**argv)
{
	MMyLib::INITIALIZE_LOG(argv[0]);
    IMyRedis t_oMyRedis;
    t_oMyRedis.InitializeRedis();
    string i;
    cin>>i;
    while("$" != i)
    {
    	redisAsyncCommand(t_oMyRedis.m_pContext, NULL, NULL, "SET %s %s", i.c_str(), i.c_str());
    	redisAsyncCommand(t_oMyRedis.m_pContext, IMyRedis::GetCallback, (char*)"end-1", "GET %s", i.c_str());
    	cin>>i;
	}
	t_oMyRedis.DisconnectRedis();
	t_oMyRedis.DispatchRedis();
    return 0;
}