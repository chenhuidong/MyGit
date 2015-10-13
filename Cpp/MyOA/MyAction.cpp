#include "MyAction.h"

int MyAction::InitializeDb(const char* in_sDbName)
{
	m_oMyData.Initialize(in_sDbName);
	return 0;
}

int MyAction::Install()
{
	//create table
	*m_oMyData.GetSession() << "CREATE TABLE IF NOT EXISTS Employee (Empno int, Name VARCHAR(256), Email VARCHAR(256), ValidFlag interger(1) default 0)", now;
    *m_oMyData.GetSession() << "CREATE TABLE IF NOT EXISTS Email (Sender VARCHAR(256) primary key, Password VARCHAR(256), Mailhost VARCHAR(256))", now;
    return 0;
}

int MyAction::SelectData()
{
	m_oMyData.ExecuteSQL("SELECT Empno, Name, Email FROM Employee where ValidFlag = 0", m_oEmployees);
    /*
	for (Employees::const_iterator it = m_oEmployees.begin(); it != m_oEmployees.end(); ++it)
    {
        std::cout << "Empno: " << it->get<0>() << 
            ", Name: " << it->get<1>() << 
            ", Email: " << it->get<2>() << std::endl;
    }
    */
    if(m_oEmployees.empty())
    {
    	throw Poco::NoRecordException("Employees no record.");
    }

    m_oMyData.ExecuteSQL("SELECT * FROM Email", m_oEmails);
    /*
    for (Emails::const_iterator it = m_oEmails.begin(); it != m_oEmails.end(); ++it)
    {
        std::cout << "Sender: " << it->get<0>() << 
            ", Password: " << it->get<1>() << 
            ", Mailhost: " << it->get<2>() << std::endl;
    }
    */
    if(m_oEmails.empty())
    {
    	throw Poco::NoRecordException("Email no record.");
    }
    return 0;
}

int MyAction::UninitializeDb()
{
	m_oMyData.Uninitialize();
	return 0;
}

int MyAction::InsertData()
{
	char iSQL[1024] = {0};
	snprintf(iSQL, sizeof(iSQL), "INSERT INTO Employee (Empno, Name, Email) VALUES(%d, \'%s\', \'%s\')", 2, "cccc", "fdsfs@163.com");
    m_oMyData.ExecuteSQL(iSQL, m_oEmployees);

   	snprintf(iSQL, sizeof(iSQL), "INSERT INTO Email (Sender, Password, Mailhost) VALUES(%d, \'%s\', \'%s\')", "chdyczx@live.com", "cccc", "smtp@163.com");
    m_oMyData.ExecuteSQL(iSQL, m_oEmails);
    return 0;
}

int MyAction::DeleteEmployee(int in_iEmpno)
{
	char iSQL[1024] = {0};
	snprintf(iSQL, sizeof(iSQL), "UPDATE Employee set ValidFlag = 1 where Empno = %d", in_iEmpno);
	m_oMyData.ExecuteSQL(iSQL, m_oEmployees);
	return 0;
}

int MyAction::UpdateEmployee()
{
    return 0;
}

int MyAction::SelectEmployee(int in_iEmpno)
{
    char iSQL[1024] = {0};
    snprintf(iSQL, sizeof(iSQL), "SELECT Empno, Name, Email FROM Employee where ValidFlag = 0 and Empno = %d", in_iEmpno);

    m_oMyData.ExecuteSQL(iSQL, m_oEmployees);
    /*
    for (Employees::const_iterator it = m_oEmployees.begin(); it != m_oEmployees.end(); ++it)
    {
        std::cout << "Empno: " << it->get<0>() << 
            ", Name: " << it->get<1>() << 
            ", Email: " << it->get<2>() << std::endl;
    }
    */
    return 0;
}

int MyAction::CreateEmail()
{
    std::wofstream ostr("/mnt/home2/51linux_LxomB0aQ/Log/1.html");
    ostr << L"<title>陈慧冬Huidong Chen&nbsp;201509工资单</title>\
<body bgcolor=\"#fffcf2\" leftmargin=\"0\" topmargin=\"0\" marginwidth=\"0\"  marginheight=\"0\">\
<h1 align=\"center\" style=\"font-family:微软雅黑;font-size=18pt;\"><br>工资通知单<br></h1>\
<table width=100%><tr><td>\
  <table width=\"80%\" align=\"center\" style=\"font-family:微软雅黑;font-size:12pt\">\
    <tr><td style=\"font-weight:bold\">陈慧冬Huidong Chen&nbsp;先生:</td></tr>\
    <tr><td align=\"center\">(员工编号:71282&nbsp; &nbsp; &nbsp;部门名称:CUC AS-South1-SPMD-NJ)</td></tr>\
  </table>\
</td></tr></table>\
      \
<table width=\"100%\"><tr><td>\
   <table align=\"center\" width=\"80%\"><tr><td><div style=\"border:1px solid #000000;\">\
    <table width=\"100%\" style=\"font-family:微软雅黑;font-size:12pt;\">\
      <tr><td height=\"25\" colspan=7></td></tr>\
      <tr style=\"font-weight:bold\"><td height=\"25\" colspan=4>一、基础工资项目</td></tr>\
<tr><td width=\"5%\"> &nbsp;  </td>\
                                       <td width=\"20%\">实发基础工资</td>\
                                       <td width=\"10%\" align=right >5300</td>\
                                       <td width=\"65%\"> </td>\
                                    </tr>\
<tr><td width=\"5%\"> &nbsp;  </td>\
                                       <td width=\"20%\">综合津贴</td>\
                                       <td width=\"10%\" align=right >1000</td>\
                                       <td width=\"65%\"> </td>\
                                    </tr>\
<tr><td width=\"5%\"> &nbsp;  </td>\
                                       <td width=\"20%\">月度岗位奖</td>\
                                       <td width=\"10%\" align=right >700</td>\
                                       <td width=\"65%\"> </td>\
                                    </tr>\
<tr><td width=\"5%\"> &nbsp;  </td>\
                                       <td width=\"20%\">基础工资项合计 </td>\
                                       <td width=\"10%\" align=right >7000</td>\
                                       <td width=\"65%\"> </td>\
                                    </tr>\
<tr><td height=\"25\" colspan=7></td></tr>\
    </table></div></td></tr>\
  </table></td></tr>\
</table>\
<table width=\"100%\"><tr><td>\
   <table align=\"center\" width=\"80%\"><tr><td><div style=\"border:1px solid #000000;\">\
    <table width=\"100%\" style=\"font-family:微软雅黑;font-size:12pt;\">\
      <tr><td height=\"25\" colspan=7></td></tr>\
      <tr style=\"font-weight:bold\"><td height=\"25\" colspan=4>二、其他税前工资项目</td></tr>\
<tr><td height=\"25\" colspan=7></td></tr>\
    </table></div></td></tr>\
  </table></td></tr>\
</table>\
<table width=\"100%\"><tr><td>\
   <table align=\"center\" width=\"80%\"><tr><td><div style=\"border:1px solid #000000;\">\
    <table width=\"100%\" style=\"font-family:微软雅黑;font-size:12pt;\">\
      <tr><td height=\"25\" colspan=7></td></tr>\
      <tr style=\"font-weight:bold\"><td height=\"25\" colspan=4>三、社保公积金扣款</td></tr>\
<tr><td width=\"5%\"> &nbsp;  </td>\
                                       <td width=\"20%\">养老保险</td>\
                                       <td width=\"10%\" align=right >424</td>\
                                       <td width=\"65%\"> </td>\
                                    </tr>\
<tr><td width=\"5%\"> &nbsp;  </td>\
                                       <td width=\"20%\">失业保险</td>\
                                       <td width=\"10%\" align=right >26.5</td>\
                                       <td width=\"65%\"> </td>\
                                    </tr>\
<tr><td width=\"5%\"> &nbsp;  </td>\
                                       <td width=\"20%\">住房扣减</td>\
                                       <td width=\"10%\" align=right >530</td>\
                                       <td width=\"65%\"> </td>\
                                    </tr>\
<tr><td width=\"5%\"> &nbsp;  </td>\
                                       <td width=\"20%\">医疗扣减</td>\
                                       <td width=\"10%\" align=right >106</td>\
                                       <td width=\"65%\"> </td>\
                                    </tr>\
<tr><td width=\"5%\"> &nbsp;  </td>\
                                       <td width=\"20%\">大病保险</td>\
                                       <td width=\"10%\" align=right >10</td>\
                                       <td width=\"65%\"> </td>\
                                    </tr>\
<tr><td width=\"5%\"> &nbsp;  </td>\
                                       <td width=\"20%\">福利扣款合计</td>\
                                       <td width=\"10%\" align=right >1096.5</td>\
                                       <td width=\"65%\"> </td>\
                                    </tr>\
<tr><td height=\"25\" colspan=7></td></tr>\
    </table></div></td></tr>\
  </table></td></tr>\
</table>\
<table width=\"100%\"><tr><td>\
   <table align=\"center\" width=\"80%\"><tr><td><div style=\"border:1px solid #000000;\">\
    <table width=\"100%\" style=\"font-family:微软雅黑;font-size:12pt;\">\
      <tr><td height=\"25\" colspan=7></td></tr>\
      <tr style=\"font-weight:bold\"><td height=\"25\" colspan=4>四、个人所得税扣减</td></tr>\
<tr><td width=\"5%\"> &nbsp;  </td>\
                                       <td width=\"20%\">所得税</td>\
                                       <td width=\"10%\" align=right >135.35</td>\
                                       <td width=\"65%\">所得税=(税前合计-个税免征额)X税率-速算扣除数 </td>\
                                    </tr>\
<tr><td width=\"5%\"> &nbsp;  </td>\
                                       <td width=\"20%\">个税合计</td>\
                                       <td width=\"10%\" align=right >135.35</td>\
                                       <td width=\"65%\"> </td>\
                                    </tr>\
<tr><td height=\"25\" colspan=7></td></tr>\
    </table></div></td></tr>\
  </table></td></tr>\
</table>\
<table width=\"100%\"><tr><td>\
   <table align=\"center\" width=\"80%\"><tr><td><div style=\"border:1px solid #000000;\">\
    <table width=\"100%\" style=\"font-family:微软雅黑;font-size:12pt;\">\
      <tr><td height=\"25\" colspan=7></td></tr>\
      <tr style=\"font-weight:bold\"><td height=\"25\" colspan=4>五、税后扣款项</td></tr>\
<tr><td width=\"5%\"> &nbsp;  </td>\
                                       <td width=\"20%\">工会互助金扣款</td>\
                                       <td width=\"10%\" align=right >10</td>\
                                       <td width=\"65%\"> </td>\
                                    </tr>\
<tr><td width=\"5%\"> &nbsp;  </td>\
                                       <td width=\"20%\">税后扣款合计</td>\
                                       <td width=\"10%\" align=right >10</td>\
                                       <td width=\"65%\"> </td>\
                                    </tr>\
<tr><td height=\"25\" colspan=7></td></tr>\
    </table></div></td></tr>\
  </table></td></tr>\
</table>\
<table width=\"100%\"><tr><td>\
   <table align=\"center\" width=\"80%\"><tr><td><div style=\"border:1px solid #000000;\">\
    <table width=\"100%\" style=\"font-family:微软雅黑;font-size:12pt;\">\
      <tr><td height=\"25\" colspan=7></td></tr>\
      <tr style=\"font-weight:bold\"><td height=\"25\" colspan=4>六、最终实发</td></tr>\
<tr><td width=\"5%\"> &nbsp;  </td>\
                                       <td width=\"20%\">税前合计</td>\
                                       <td width=\"10%\" align=right >5903.5</td>\
                                       <td width=\"65%\">税前合计=基础工资项目+其他税前工资项目-社保公积金扣款  </td>\
                                    </tr>\
<tr><td width=\"5%\"> &nbsp;  </td>\
                                       <td width=\"20%\">扣款合计</td>\
                                       <td width=\"10%\" align=right >145.35</td>\
                                       <td width=\"65%\">扣款合计=所得税+税后其他扣款项 </td>\
                                    </tr>\
<tr><td width=\"5%\"> &nbsp;  </td>\
                                       <td width=\"20%\">最终实发</td>\
                                       <td width=\"10%\" align=right >5758.15</td>\
                                       <td width=\"65%\"> </td>\
                                    </tr>\
<tr><td height=\"25\" colspan=7></td></tr>\
    </table></div></td></tr>\
  </table></td></tr>\
</table>\
\
<table width=\"100%\"><tr><td>\
  <table align=\"center\" width=\"80%\"><tr><td>\
    <table width=\"100%\" style=\"font-family:微软雅黑;font-size:12pt; font-weight:bold;\">\
<tr><td align=\"right\"> 亚信集团人力资源部</td></tr>\
                                   <tr><td align=\"right\">2015-10-08 13:06:45</td></tr>\
                                   <tr><td align=\"right\" style=\"font-family:微软雅黑;font-size:4pt; align=\"right\">71282</td></tr> \
\
      <tr><td colspan=7 height=\"25\"></td></tr>\
    </table>\
  </td></tr></table>\
</td></tr></table>\
" << std::endl;
    ostr.close();
    return 0;
}

int MyAction::CreateEmails()
{
    CreateEmail();
    return 0;
}

int MyAction::SendEmail()
{   /*
    for (Employees::const_iterator it = m_oEmployees.begin(); it != m_oEmployees.end(); ++it)
    {
        std::cout << "Empno: " << it->get<0>() << 
            ", Name: " << it->get<1>() << 
            ", Email: " << it->get<2>() << std::endl;
    }

    for (Emails::const_iterator it = m_oEmails.begin(); it != m_oEmails.end(); ++it)
    {
        std::cout << "Sender: " << it->get<0>() << 
            ", Password: " << it->get<1>() << 
            ", Mailhost: " << it->get<2>() << std::endl;
    }
    */
    
    return 0;
}
