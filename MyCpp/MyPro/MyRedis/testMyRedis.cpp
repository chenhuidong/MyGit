#include "MyRedis.h"

int main()
{
	MMyLib::g_pRedisConn->run(command("SET") << "foo" << "bar" );
	reply t_oReply = MMyLib::g_pRedisConn->run(command("GET") << "foo" );
	std::cout << "FOO is: " << t_oReply.str() << std::endl;

	MMyLib::g_pRedisConn->run(command("hset") << "student.chenhuidong" << "name" );
	t_oReply = MMyLib::g_pRedisConn->run(command("GET") << "foo" );
	std::cout << "FOO is: " << t_oReply.str() << std::endl;
	return 0;
}