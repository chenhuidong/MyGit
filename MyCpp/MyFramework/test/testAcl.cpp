#include <iostream>
#include "lib_acl_cpp/include/acl_cpp/lib_acl.hpp"

using namespace std;
int main()
{
	acl::redis_client_cluster cluster;
	const char *redis_addr  = "172.17.138.176:7000";//设置连接的数据库地址

	int conn_timeout       = 10;//连接redis-server的超时时间（秒）
	int rw_timeout          = 10;//与redis-server进行通信IO的超时时间（秒）
	int max_threads        = 100;//最大线程线程数
	cluster.set(redis_addr, max_threads, conn_timeout, rw_timeout);//设置集群中的任何一个地址就行

	//acl::redis_client conn(redis_addr, conn_timeout, rw_timeout);//设置连接的客户端
	//acl::redis_string string_cmd(&conn);//单个节点模式

	acl::redis_string string_cmd(&cluster,max_threads);//集群连接模式

	const char *key="acl_redis";

	acl::string result = "";
	if(string_cmd.get(key,result) == false){
	   return false;
	}
	printf("get key: %s ok, value: %s\r\n", key, result.c_str());
	return true;
}