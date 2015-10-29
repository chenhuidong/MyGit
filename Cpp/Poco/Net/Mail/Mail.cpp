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

/*
const unsigned char PocoLogo[] =
{
	#include "PocoLogo.hpp"
};
*/

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
		//application/octet-stream
		std::ostringstream ostr;
		ostr << "<title>陈慧冬Huidong Chen&nbsp;201509工资单</title>\r\n\
<body bgcolor=\"#fffcf2\" leftmargin=\"0\" topmargin=\"0\" marginwidth=\"0\"  marginheight=\"0\">\r\n\
<h1 align=\"center\" style=\"font-family:微软雅黑;font-size=18pt;\"><br>工资通知单<br></h1>\r\n\
<table width=100%><tr><td>\r\n\
  <table width=\"80%\" align=\"center\" style=\"font-family:微软雅黑;font-size:12pt\">\r\n\
    <tr><td style=\"font-weight:bold\">陈慧冬Huidong Chen&nbsp;先生:</td></tr>\r\n\
    <tr><td align=\"center\">(员工编号:71282&nbsp; &nbsp; &nbsp;部门名称:CUC AS-South1-SPMD-NJ)</td></tr>\r\n\
  </table>\r\n\
</td></tr></table>\r\n\
      \r\n\
<table width=\"100%\"><tr><td>\r\n\
   <table align=\"center\" width=\"80%\"><tr><td><div style=\"border:1px solid #000000;\">\r\n\
    <table width=\"100%\" style=\"font-family:微软雅黑;font-size:12pt;\">\r\n\
      <tr><td height=\"25\" colspan=7></td></tr>\r\n\
      <tr style=\"font-weight:bold\"><td height=\"25\" colspan=4>一、基础工资项目</td></tr>\r\n\
<tr><td width=\"5%\"> &nbsp;  </td>\r\n\
                                       <td width=\"20%\">实发基础工资</td>\r\n\
                                       <td width=\"10%\" align=right >5300</td>\r\n\
                                       <td width=\"65%\"> </td>\r\n\
                                    </tr>\r\n\
<tr><td width=\"5%\"> &nbsp;  </td>\r\n\
                                       <td width=\"20%\">综合津贴</td>\r\n\
                                       <td width=\"10%\" align=right >1000</td>\r\n\
                                       <td width=\"65%\"> </td>\r\n\
                                    </tr>\r\n\
<tr><td width=\"5%\"> &nbsp;  </td>\r\n\
                                       <td width=\"20%\">月度岗位奖</td>\r\n\
                                       <td width=\"10%\" align=right >700</td>\r\n\
                                       <td width=\"65%\"> </td>\r\n\
                                    </tr>\r\n\
<tr><td width=\"5%\"> &nbsp;  </td>\r\n\
                                       <td width=\"20%\">基础工资项合计 </td>\r\n\
                                       <td width=\"10%\" align=right >7000</td>\r\n\
                                       <td width=\"65%\"> </td>\r\n\
                                    </tr>\r\n\
<tr><td height=\"25\" colspan=7></td></tr>\r\n\
    </table></div></td></tr>\r\n\
  </table></td></tr>\r\n\
</table>\r\n\
<table width=\"100%\"><tr><td>\r\n\
   <table align=\"center\" width=\"80%\"><tr><td><div style=\"border:1px solid #000000;\">\r\n\
    <table width=\"100%\" style=\"font-family:微软雅黑;font-size:12pt;\">\r\n\
      <tr><td height=\"25\" colspan=7></td></tr>\r\n\
      <tr style=\"font-weight:bold\"><td height=\"25\" colspan=4>二、其他税前工资项目</td></tr>\r\n\
<tr><td height=\"25\" colspan=7></td></tr>\r\n\
    </table></div></td></tr>\r\n\
  </table></td></tr>\r\n\
</table>\r\n\
<table width=\"100%\"><tr><td>\r\n\
   <table align=\"center\" width=\"80%\"><tr><td><div style=\"border:1px solid #000000;\">\r\n\
    <table width=\"100%\" style=\"font-family:微软雅黑;font-size:12pt;\">\r\n\
      <tr><td height=\"25\" colspan=7></td></tr>\r\n\
      <tr style=\"font-weight:bold\"><td height=\"25\" colspan=4>三、社保公积金扣款</td></tr>\r\n\
<tr><td width=\"5%\"> &nbsp;  </td>\r\n\
                                       <td width=\"20%\">养老保险</td>\r\n\
                                       <td width=\"10%\" align=right >424</td>\r\n\
                                       <td width=\"65%\"> </td>\r\n\
                                    </tr>\r\n\
<tr><td width=\"5%\"> &nbsp;  </td>\r\n\
                                       <td width=\"20%\">失业保险</td>\r\n\
                                       <td width=\"10%\" align=right >26.5</td>\r\n\
                                       <td width=\"65%\"> </td>\r\n\
                                    </tr>\r\n\
<tr><td width=\"5%\"> &nbsp;  </td>\r\n\
                                       <td width=\"20%\">住房扣减</td>\r\n\
                                       <td width=\"10%\" align=right >530</td>\r\n\
                                       <td width=\"65%\"> </td>\r\n\
                                    </tr>\r\n\
<tr><td width=\"5%\"> &nbsp;  </td>\r\n\
                                       <td width=\"20%\">医疗扣减</td>\r\n\
                                       <td width=\"10%\" align=right >106</td>\r\n\
                                       <td width=\"65%\"> </td>\r\n\
                                    </tr>\r\n\
<tr><td width=\"5%\"> &nbsp;  </td>\r\n\
                                       <td width=\"20%\">大病保险</td>\r\n\
                                       <td width=\"10%\" align=right >10</td>\r\n\
                                       <td width=\"65%\"> </td>\r\n\
                                    </tr>\r\n\
<tr><td width=\"5%\"> &nbsp;  </td>\r\n\
                                       <td width=\"20%\">福利扣款合计</td>\r\n\
                                       <td width=\"10%\" align=right >1096.5</td>\r\n\
                                       <td width=\"65%\"> </td>\r\n\
                                    </tr>\r\n\
<tr><td height=\"25\" colspan=7></td></tr>\r\n\
    </table></div></td></tr>\r\n\
  </table></td></tr>\r\n\
</table>\r\n\
<table width=\"100%\"><tr><td>\r\n\
   <table align=\"center\" width=\"80%\"><tr><td><div style=\"border:1px solid #000000;\">\r\n\
    <table width=\"100%\" style=\"font-family:微软雅黑;font-size:12pt;\">\r\n\
      <tr><td height=\"25\" colspan=7></td></tr>\r\n\
      <tr style=\"font-weight:bold\"><td height=\"25\" colspan=4>四、个人所得税扣减</td></tr>\r\n\
<tr><td width=\"5%\"> &nbsp;  </td>\r\n\
                                       <td width=\"20%\">所得税</td>\r\n\
                                       <td width=\"10%\" align=right >135.35</td>\r\n\
                                       <td width=\"65%\">所得税=(税前合计-个税免征额)X税率-速算扣除数 </td>\r\n\
                                    </tr>\r\n\
<tr><td width=\"5%\"> &nbsp;  </td>\r\n\
                                       <td width=\"20%\">个税合计</td>\r\n\
                                       <td width=\"10%\" align=right >135.35</td>\r\n\
                                       <td width=\"65%\"> </td>\r\n\
                                    </tr>\r\n\
<tr><td height=\"25\" colspan=7></td></tr>\r\n\
    </table></div></td></tr>\r\n\
  </table></td></tr>\r\n\
</table>\r\n\
<table width=\"100%\"><tr><td>\r\n\
   <table align=\"center\" width=\"80%\"><tr><td><div style=\"border:1px solid #000000;\">\r\n\
    <table width=\"100%\" style=\"font-family:微软雅黑;font-size:12pt;\">\r\n\
      <tr><td height=\"25\" colspan=7></td></tr>\r\n\
      <tr style=\"font-weight:bold\"><td height=\"25\" colspan=4>五、税后扣款项</td></tr>\r\n\
<tr><td width=\"5%\"> &nbsp;  </td>\r\n\
                                       <td width=\"20%\">工会互助金扣款</td>\r\n\
                                       <td width=\"10%\" align=right >10</td>\r\n\
                                       <td width=\"65%\"> </td>\r\n\
                                    </tr>\r\n\
<tr><td width=\"5%\"> &nbsp;  </td>\r\n\
                                       <td width=\"20%\">税后扣款合计</td>\r\n\
                                       <td width=\"10%\" align=right >10</td>\r\n\
                                       <td width=\"65%\"> </td>\r\n\
                                    </tr>\r\n\
<tr><td height=\"25\" colspan=7></td></tr>\r\n\
    </table></div></td></tr>\r\n\
  </table></td></tr>\r\n\
</table>\r\n\
<table width=\"100%\"><tr><td>\r\n\
   <table align=\"center\" width=\"80%\"><tr><td><div style=\"border:1px solid #000000;\">\r\n\
    <table width=\"100%\" style=\"font-family:微软雅黑;font-size:12pt;\">\r\n\
      <tr><td height=\"25\" colspan=7></td></tr>\r\n\
      <tr style=\"font-weight:bold\"><td height=\"25\" colspan=4>六、最终实发</td></tr>\r\n\
<tr><td width=\"5%\"> &nbsp;  </td>\r\n\
                                       <td width=\"20%\">税前合计</td>\r\n\
                                       <td width=\"10%\" align=right >5903.5</td>\r\n\
                                       <td width=\"65%\">税前合计=基础工资项目+其他税前工资项目-社保公积金扣款  </td>\r\n\
                                    </tr>\r\n\
<tr><td width=\"5%\"> &nbsp;  </td>\r\n\
                                       <td width=\"20%\">扣款合计</td>\r\n\
                                       <td width=\"10%\" align=right >145.35</td>\r\n\
                                       <td width=\"65%\">扣款合计=所得税+税后其他扣款项 </td>\r\n\
                                    </tr>\r\n\
<tr><td width=\"5%\"> &nbsp;  </td>\r\n\
                                       <td width=\"20%\">最终实发</td>\r\n\
                                       <td width=\"10%\" align=right >5758.15</td>\r\n\
                                       <td width=\"65%\"> </td>\r\n\
                                    </tr>\r\n\
<tr><td height=\"25\" colspan=7></td></tr>\r\n\
    </table></div></td></tr>\r\n\
  </table></td></tr>\r\n\
</table>\r\n\
\r\n\
<table width=\"100%\"><tr><td>\r\n\
  <table align=\"center\" width=\"80%\"><tr><td>\r\n\
    <table width=\"100%\" style=\"font-family:微软雅黑;font-size:12pt; font-weight:bold;\">\r\n\
<tr><td align=\"right\"> 亚信集团人力资源部</td></tr>\r\n\
                                   <tr><td align=\"right\">2015-10-08 13:06:45</td></tr>\r\n\
                                   <tr><td align=\"right\" style=\"font-family:微软雅黑;font-size:4pt; align=\"right\">71282</td></tr> \r\n\
\r\n\
      <tr><td colspan=7 height=\"25\"></td></tr>\r\n\
    </table>\r\n\
  </td></tr></table>\r\n\
</td></tr></table>" << std::endl;
		message.addAttachment("1", new StringPartSource(ostr.str(), "text/plain", "1.html"));
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
//./main smtp.163.com chdyczx@163.com 123456 chdyczx@live.com