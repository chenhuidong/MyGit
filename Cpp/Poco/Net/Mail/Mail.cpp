//
// Mail.cpp
//
// $Id: //poco/1.4/Net/samples/Mail/src/Mail.cpp#2 $
//
// This sample demonstrates the MailMessage and SMTPClientSession classes.
//
// Copyright (c) 2005-2011, Applied Informatics Software Engineering GmbH.
// and Contributors.
//
// SPDX-License-Identifier:	BSL-1.0
//


#include "Poco/Net/MailMessage.h"
#include "Poco/Net/MailRecipient.h"
#include "Poco/Net/SMTPClientSession.h"
#include "Poco/Net/StringPartSource.h"
#include "Poco/Path.h"
#include "Poco/Exception.h"
#include <iostream>


using Poco::Net::MailMessage;
using Poco::Net::MailRecipient;
using Poco::Net::SMTPClientSession;
using Poco::Net::StringPartSource;
using Poco::Path;
using Poco::Exception;


const unsigned char PocoLogo[] =
{
	#include "PocoLogo.hpp"
};


int main(int argc, char** argv)
{
	if (argc != 5)
	{
		Path p(argv[0]);
		std::cerr << "usage: " << p.getBaseName() << " <mailhost> <sender> <password> <recipient>" << std::endl;
		std::cerr << "       Send an email greeting from <sender> to <recipient>," << std::endl;
		std::cerr << "       using the SMTP server at <mailhost>." << std::endl;
		return 1;
	}
	
	std::string mailhost(argv[1]);
	std::string sender(argv[2]);
	std::string password(argv[3]);
	std::string recipient(argv[4]);
	
	try
	{
		MailMessage message;
		message.setSender(sender);
		message.addRecipient(MailRecipient(MailRecipient::PRIMARY_RECIPIENT, recipient));
		message.setSubject("Hello from the POCO C++ Libraries");
		std::string content;
		content += "Hello ";
		content += recipient;
		content += ",\r\n\r\n";
		content += "This is a greeting from the POCO C++ Libraries.\r\n\r\n";
		//std::string logo(reinterpret_cast<const char*>(PocoLogo), sizeof(PocoLogo));
		message.addContent(new StringPartSource(content));
		//message.addAttachment("logo", new StringPartSource(logo, "image/gif"));
		
		SMTPClientSession session(mailhost);

		//session.login();
		session.login(SMTPClientSession::AUTH_LOGIN, sender, password);

		session.sendMessage(message);
		session.close();
	}
	catch (Exception& exc)
	{
		std::cerr << exc.displayText() << std::endl;
		return 1;
	}
	return 0;
}

//g++ Mail.cpp -omain -lPocoNet
//./main smtp.163.com chdyczx@163.com Chenhd@420462 chdyczx@live.com