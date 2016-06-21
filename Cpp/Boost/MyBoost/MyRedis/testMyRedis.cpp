#include "MyRedis.h"
using namespace MMyLib;

int main(int argc, char**argv)
{
	MMyLib::INITIALIZE_LOG(argv[0]);
    IMyRedis t_oMyRedis;
    t_oMyRedis.InitializeRedis();
    //string key, value;
    //cin>>key >>value;
    //while("$" != key)
    //{
    	string key = "2", value="3";
    	LOG_INFO<< "set "<< key<< " "<< value<< endl;
    	redisAsyncCommand(t_oMyRedis.m_pContext, NULL, NULL, "SET %s %s", key.c_str(), value.c_str());
    	redisAsyncCommand(t_oMyRedis.m_pContext, IMyRedis::GetCallback, (char*)key.c_str(), "GET %s", key.c_str());

    	key = "4", value="5";
    	LOG_INFO<< "set "<< key<< " "<< value<< endl;
    	redisAsyncCommand(t_oMyRedis.m_pContext, NULL, NULL, "SET %s %s", key.c_str(), value.c_str());
    	redisAsyncCommand(t_oMyRedis.m_pContext, IMyRedis::GetCallback, (char*)key.c_str(), "GET %s", key.c_str());
    	//cin>>key >>value;
	//}
	t_oMyRedis.DisconnectRedis();
	t_oMyRedis.DispatchRedis();
    return 0;
}