#ifndef __MY_OA_MY_EMAIL_H_
#define __MY_OA_MY_EMAIL_H_

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

class MyEmail
{
public:
	MyEmail()
	{
		mailhost = "smtp.163.com";
		sender = "chdyczx@163.com";
		password = "Chenhd@420462";
		recipient = "chdyczx@live.com";
	}
	~MyEmail(){}
	int SendEmail();

private:
	int CreateHtml(/*std::ostringstream &ostr*/);
	int CreateEmail();
	int CreateEmails();
	
private:
	MailMessage m_oMessage;
	std::string mailhost;
	std::string sender;
	std::string password;
	std::string recipient;
};

#endif