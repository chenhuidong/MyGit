#include "MyRedis.h"

int main()
{
	const char* t_sStr = "bar";
	MMyLib::g_pRedisConn->run(command("SET") << "foo" << t_sStr );
	const char* t_sStr1 = "foo";
	reply t_oReply = MMyLib::g_pRedisConn->run(command("GET") << t_sStr1 );
	std::cout << "FOO is: " << t_oReply.str() << std::endl;

	MMyLib::g_pRedisConn->run(command("hset")<< "student.chenhuidong"<< "name"<< "chenhuidong");
	t_oReply = MMyLib::g_pRedisConn->run(command("hget") << "student.chenhuidong"<< "name");
	std::cout << "name is: " << t_oReply.str() << std::endl;
	return 0;
}