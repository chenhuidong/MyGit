#include "MyEmail.h"

Poco::AtomicCounter MyEmail::counter;

int MyEmail::CreateHtml()
{
  std::ofstream ostr("/mnt/home2/51linux_LxomB0aQ/Log/1.html");
	ostr << "<!DOCTYPE html>\r\n\
<html lang=\"en\"> \r\n\
<head>\r\n\
<meta charset=\"utf-8\"/>\r\n\
  <title>陈开Kai Chen&nbsp;201509工资单</title>\r\n\
<body bgcolor=\"#fffcf2\" leftmargin=\"0\" topmargin=\"0\" marginwidth=\"0\"  marginheight=\"0\">\r\n\
<h1 align=\"center\" style=\"font-family:微软雅黑;font-size=18pt;\"><br>工资通知单<br></h1>\r\n\
<table width=100%><tr><td>\r\n\
  <table width=\"80%\" align=\"center\" style=\"font-family:微软雅黑;font-size:12pt\">\r\n\
    <tr><td style=\"font-weight:bold\">陈开Kai Chen&nbsp;先生:</td></tr>\r\n\
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
<tr><td align=\"right\"> 江苏苏雪达人力资源部</td></tr>\r\n\
                                   <tr><td align=\"right\">2015-10-08 13:06:45</td></tr>\r\n\
                                   <tr><td align=\"right\" style=\"font-family:微软雅黑;font-size:4pt; align=\"right\">71282</td></tr> \r\n\
\r\n\
      <tr><td colspan=7 height=\"25\"></td></tr>\r\n\
    </table>\r\n\
  </td></tr></table>\r\n\
</td></tr></table>" << std::endl;

	return 0;
}

int MyEmail::CreateEmail()
{
  /*
	m_oMessage.setSender(sender);
	m_oMessage.addRecipient(MailRecipient(MailRecipient::PRIMARY_RECIPIENT, recipient));
	m_oMessage.setSubject(MailMessage::encodeWord("工资条"));
	std::string content;
	content += "您好：\r\n";
	content += "附件为您的本月工资条。\r\n\r\n";
	m_oMessage.addContent(new StringPartSource(content));
	CreateHtml();
	m_oMessage.addAttachment("1", new FilePartSource("/mnt/home2/51linux_LxomB0aQ/Log/1.html"));
	*/
  return 0;
}

void MyEmail::SendEmail(void *in_pMyDatas)
{
  /*
	CreateEmail();
	SMTPClientSession session(mailhost);
	session.login(SMTPClientSession::AUTH_LOGIN, sender, password);
	session.sendMessage(m_oMessage);
	session.close();
  */
  /*
  MyDatas* t_pMyDatas=(MyDatas*)in_pMyDatas;
  for (Employees::const_iterator it = t_pMyDatas->m_oEmployees.begin(); it != t_pMyDatas->m_oEmployees.end(); ++it)
  {
    std::cout << "Empno: " << it->get<0>() << 
    ", Name: " << it->get<1>() << 
    ", Email: " << it->get<2>() << std::endl;
  }

  for (Emails::const_iterator it = t_pMyDatas->m_oEmails.begin(); it != t_pMyDatas->m_oEmails.end(); ++it)
  {
    std::cout << "Sender: " << it->get<0>() << 
    ", Password: " << it->get<1>() << 
    ", Mailhost: " << it->get<2>() << std::endl;
  }

  for (Salarys::const_iterator it = t_pMyDatas->m_oSalarys.begin(); it != t_pMyDatas->m_oSalarys.end(); ++it)
  {
    std::cout<< it->get<0>()<< " "<< it->get<1>()<< " "<< it->get<2>()<< " "<< it->get<3>()<< " "<<
     it->get<4>()<< " "<< it->get<5>()<< " "<< it->get<6>()<< " "<< it->get<7>()<< " "<<
      it->get<8>()<< " "<< it->get<9>()<< " "<< it->get<10>()<< " "<< it->get<11>()<< " "<<  std::endl;
  }
  */
  
  MyDatas* t_pMyDatas=(MyDatas*)in_pMyDatas;
  int t_iEmployeesNum = t_pMyDatas->m_oEmployees.size();
  //int t_iEmployeesNum = 500;
  /*
  for (int i=0; i<t_iEmployeesNum; i++)
  {
    std::cout << "Empno: " << t_pMyDatas->m_oEmployees[i].get<0>() << 
    ", Name: " << t_pMyDatas->m_oEmployees[i].get<1>() << 
    ", Email: " << t_pMyDatas->m_oEmployees[i].get<2>() << std::endl;
  }
  */

  int t_iIndex = MyEmail::GetCounter();
  while(t_iIndex < t_iEmployeesNum)
  {
    //std::cout<< t_iIndex<< std::endl;
    std::cout << "Empno: " << t_pMyDatas->m_oEmployees[t_iIndex].get<0>() << 
    ", Name: " << t_pMyDatas->m_oEmployees[t_iIndex].get<1>() << 
    ", Email: " << t_pMyDatas->m_oEmployees[t_iIndex].get<2>() << std::endl;

    int t_iEmpno = t_pMyDatas->m_oEmployees[t_iIndex].get<0>();

    Salarys::const_iterator it = std::find_if(t_pMyDatas->m_oSalarys.begin(), t_pMyDatas->m_oSalarys.end(), CComp<int>(t_iEmpno));

    if(it == t_pMyDatas->m_oSalarys.end())
    {
      std::cout<< "salary relation is empty"<< std::endl;
      return;
    }

    std::cout<< it->get<0>()<< " "<< it->get<1>()<< " "<< it->get<2>()<< " "<< it->get<3>()<< " "<<
      it->get<4>()<< " "<< it->get<5>()<< " "<< it->get<6>()<< " "<< it->get<7>()<< " "<<
      it->get<8>()<< " "<< it->get<9>()<< " "<< it->get<10>()<< " "<< it->get<11>()<< " "<<  std::endl;

    t_iIndex = MyEmail::GetCounter();
  }
}

int MyEmail::SendEmails(MyDatas& in_oMyDatas)
{
  /*
  for (Employees::const_iterator it = in_oMyDatas.m_oEmployees.begin(); it != in_oMyDatas.m_oEmployees.end(); ++it)
  {
    std::cout << "Empno: " << it->get<0>() << 
    ", Name: " << it->get<1>() << 
    ", Email: " << it->get<2>() << std::endl;
  }

  for (Emails::const_iterator it = in_oMyDatas.m_oEmails.begin(); it != in_oMyDatas.m_oEmails.end(); ++it)
  {
    std::cout << "Sender: " << it->get<0>() << 
    ", Password: " << it->get<1>() << 
    ", Mailhost: " << it->get<2>() << std::endl;
  }

  for (Salarys::const_iterator it = in_oMyDatas.m_oSalarys.begin(); it != in_oMyDatas.m_oSalarys.end(); ++it)
  {
    std::cout<< it->get<0>()<< " "<< it->get<1>()<< " "<< it->get<2>()<< " "<< it->get<3>()<< " "<<
     it->get<4>()<< " "<< it->get<5>()<< " "<< it->get<6>()<< " "<< it->get<7>()<< " "<<
      it->get<8>()<< " "<< it->get<9>()<< " "<< it->get<10>()<< " "<< it->get<11>()<< " "<<  std::endl;
  }
  */
  int t_iThreadNum = in_oMyDatas.m_oEmails.size();
  //int t_iThreadNum = 2;
  Poco::Thread *t_aThread[t_iThreadNum];
  
  for(int i=0; i<t_iThreadNum; i++)
  {
    Poco::Thread *t_pThread = new Poco::Thread();
    t_aThread[i] = t_pThread;
    t_pThread->start(MyEmail::SendEmail, (void *)(&in_oMyDatas));
  }

  for(int i=0; i<t_iThreadNum; i++)
  {
    t_aThread[i]->join();
  }

  for(int i=0; i<t_iThreadNum; i++)
  {
    delete t_aThread[i];
  }

  return 0;
}

int MyEmail::GetCounter()
{
  return MyEmail::counter++;
}

