#include "MyRedis.h"
using namespace MMyLib;

int main(int argc, char**argv)
{
	MMyLib::INITIALIZE_LOG(argv[0]);
	IMyRedis t_oMyRedis;
	t_oMyRedis.InitializeRedis();

	while(true)
	{
		string key, value;
		cin>> key>> value;
		LOG_INFO<< "set "<< key<< " "<< value<< endl;
		redisAsyncCommand(t_oMyRedis.m_pContext, NULL, NULL, "SET %s %s", key.c_str(), value.c_str());
		redisAsyncCommand(t_oMyRedis.m_pContext, IMyRedis::GetCallback, (char*)key.c_str(), "GET %s", key.c_str());
		t_oMyRedis.DispatchRedis();
	}
	//t_oMyRedis.DisconnectRedis();
	
	return 0;
}