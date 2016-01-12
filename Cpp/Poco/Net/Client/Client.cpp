#include "Poco/Net/StreamSocket.h"
#include "Poco/Net/SocketStream.h"
#include "Poco/Net/SocketAddress.h"
#include "Poco/StreamCopier.h"
#include "Poco/Path.h"
#include "Poco/Exception.h"
#include <iostream>


using Poco::Net::StreamSocket;
using Poco::Net::SocketStream;
using Poco::Net::SocketAddress;
using Poco::StreamCopier;
using Poco::Path;
using Poco::Exception;


int main(int argc, char** argv)
{
	const std::string HOST("127.0.0.1");
	const unsigned short PORT = 54321;
	
	try
	{
		SocketAddress sa(HOST, PORT);
		StreamSocket sock(sa);
		SocketStream str(sock);
		
		sock.shutdownSend();
		StreamCopier::copyStream(str, std::cout);
	}
	catch (Exception& exc)
	{
		std::cerr << exc.displayText() << std::endl;
		return 1;
	}
	
	return 0;
}
