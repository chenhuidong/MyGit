#ifndef __MY_BASE64_H_
#define __MY_BASE64_H_
#include "Poco/Base64Decoder.h"
#include "Poco/Base64Encoder.h"
#include "Poco/StreamCopier.h"
#include <string>
#include <sstream>

using Poco::Base64Decoder;
using Poco::Base64Encoder;
using Poco::StreamCopier;

class MyBase64
{
public:
	static int Base64Encode(std::string &in_sSource, std::string &in_sDest);
	static int Base64Decode(std::string &in_sSource, std::string &in_sDest);
};

#endif 