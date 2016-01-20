#include "MyBase64.h"

int MyBase64::Base64Encode(std::string &in_sSource, std::string &in_sDest)
{
	return 0;
}

int MyBase64::Base64Decode(std::string &in_sSource, std::string &in_sDest)
{
	std::stringstream t_sSourceStream, t_sDestStream;
	t_sSourceStream << in_sSource;

	Base64Decoder decoder(t_sSourceStream);
	StreamCopier::copyStream(decoder, t_sDestStream);
	t_sDestStream >> in_sDest;
	return 0;
}