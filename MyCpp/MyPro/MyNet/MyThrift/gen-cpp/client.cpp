#include "Serv.h"  // 替换成你的.h  
#include <transport/TSocket.h>  
#include <transport/TBufferTransports.h>  
#include <protocol/TBinaryProtocol.h>  

using namespace apache::thrift;  
using namespace apache::thrift::protocol;  
using namespace apache::thrift::transport;  

using boost::shared_ptr;  

int main(int argc, char **argv) {  
	boost::shared_ptr<TSocket> socket(new TSocket("127.0.0.1", 54321));  
	boost::shared_ptr<TTransport> transport(new TBufferedTransport(socket));  
	boost::shared_ptr<TProtocol> protocol(new TBinaryProtocol(transport));  

	transport->open();  

    //begin
	Student s;
	s.sno = 123;
	s.sname = "xiaoshe";
	s.ssex = 1;
	s.sage = 30;

	ServClient client(protocol);
	client.put(s); 
	//end
	
	transport->close();  

	return 0;  
} 