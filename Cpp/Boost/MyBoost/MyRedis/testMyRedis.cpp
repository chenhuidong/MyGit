#include "MyRedis.h"

int main()
{
	MMyLib::g_pConn->run(command("SET") << "foo" << "bar" );
	reply t_oReply = MMyLib::g_pConn->run(command("GET") << "foo" );
	std::cout << "FOO is: " << t_oReply.str() << std::endl;

	MMyLib::g_pConn->run(command("hset") << "student.chenhuidong" << "name" );
	reply t_oReply = MMyLib::g_pConn->run(command("GET") << "foo" );
	std::cout << "FOO is: " << t_oReply.str() << std::endl;
	return 0;
}