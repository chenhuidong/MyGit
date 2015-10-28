#ifndef __MY_OA_MY_EMAIL_H_
#define __MY_OA_MY_EMAIL_H_

#include "../stdafx.h"
#include "Poco/Net/MailMessage.h"
#include "Poco/Net/MailRecipient.h"
#include "Poco/Net/SMTPClientSession.h"
#include "Poco/Net/StringPartSource.h"
#include "Poco/Net/FilePartSource.h"
#include "Poco/Path.h"
#include "Poco/Exception.h"
#include "MyStruct.h"
#include "MyData.h"
#include "MyException.h"

using Poco::Net::MailMessage;
using Poco::Net::MailRecipient;
using Poco::Net::SMTPClientSession;
using Poco::Net::StringPartSource;
using Poco::Net::FilePartSource;
using Poco::Path;
using Poco::Exception;

class MyEmail
{
public:
	MyEmail()
	{	
	}
	~MyEmail(){}
	int SendEmails(MyDatas& in_oMyDatas);

private:
	static void SendEmail(void *in_pMyDatas);
	static int CreateHtml();
	static int CreateEmail(MailMessage &in_oMessage, Employee &in_oEmployee, Salary &in_oSalary);
	static int GetEmployeeCounter();
	static int GetEmailCounter();
	
private:
	static Poco::AtomicCounter m_oEmailCounter;
	static Poco::AtomicCounter m_oEmployeeCounter;
};

class CComp
{
public:
	CComp(int in_iN):m_iN(in_iN){}
	bool operator()(Salary& lhs)
	{
		return (lhs.get<0>()==m_iN);
	}
private:
	int m_iN;
};

#endif