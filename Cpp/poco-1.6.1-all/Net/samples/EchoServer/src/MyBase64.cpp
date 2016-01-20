#include "MyBase64.h"

int MyBase64::Base64Encode(std::string &in_sSource, std::string &in_sDest)
{
	return 0;
}

int MyBase64::Base64Decode(std::string &in_sSource, std::string &in_sDest)
{
	Base64Decoder decoder(in_sSource);
	StreamCopier::copyStream(decoder, in_sDest);
	return 0;
}