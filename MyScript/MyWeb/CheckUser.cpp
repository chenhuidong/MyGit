#include "CheckUser.h"

int UserCheck::InitializeDb()
{
    m_oMyDb.Initialize((MMyLib::MyDb::DbType)1, "host=127.0.0.1;port=3306;user=root;password=Chenhd@443420;db=mysql");
    return 0;
}

int UserCheck::UninitializeDb()
{
    m_oMyDb.Uninitialize();
    return 0;
}

int UserCheck::UserInputCheck(char* out_sUsername, char* out_sPassword)
{
    
    /*char *t_sSignUp = getenv("QUERY_STRING" );
    if(!t_sSignUp)
    {
        cout<< "QUERY_STRING is empty."<< "<br>\n"<< endl;
        return -1;
    }
    */
    sscanf(t_sSignUp,"username=%[^&]&password=%s",out_sUsername, out_sPassword);

    if((0==strlen(out_sUsername)) || (0==strlen(out_sPassword)))
    {
        cout<< "username or password is empty."<< "<br>\n"<< endl;
        return -1;
    }

    if(0 != SpecialWordCheck(out_sUsername))
    {
        cout<< "your username contains special word."<< "<br>\n"<< endl;
        return -1;
    }

    if(0 != SpecialWordCheck(out_sPassword))
    {
        cout<< "your password contains special word."<< "<br>\n"<< endl;
        return -1;
    }
    return 0;
}

int UserCheck::SpecialWordCheck(char* in_sStr)
{
    for(int i=0; i<strlen(in_sStr); ++i)
    {
        if( (in_sStr[i]>='a'&&in_sStr[i]<='z')
            ||(in_sStr[i]>='A'&&in_sStr[i]<='Z')
            ||(in_sStr[i]>='0'&&in_sStr[i]<='9'))
        {
            continue;
        }
        else
        {
            return -1;
        }
    }
    return 0;
}

int UserCheck::ExistUsername(char* in_sUsername)
{
    LOG_INFO<< "ExistUsername begin.";

    char iSQL[1024] = {0};
    snprintf(iSQL, sizeof(iSQL), "select m_id, m_username, m_password, m_instance from wizard_users where m_username = '%s'", in_sUsername);
    m_oMyDb.ExecuteSQL(iSQL, m_oUsers);
    
    LOG_INFO<< "ExistUsername end.";
    return m_oUsers.size();
}

int UserCheck::ExistUsernamePassword(char* in_sUsername, char* in_sPassword)
{
    LOG_INFO<< "ExistUsernamePassword begin.";

    char iSQL[1024] = {0};
    snprintf(iSQL, sizeof(iSQL), "select m_id, m_username, m_password, m_instance from wizard_users where m_username = '%s' and m_password = '%s'", in_sUsername, in_sPassword);
    m_oMyDb.ExecuteSQL(iSQL, m_oUsers);
    
    LOG_INFO<< "ExistUsernamePassword end.";
    return m_oUsers.size();
}

int UserCheck::InsertUsers(char* in_sUsername, char* in_sPassword)
{
    LOG_INFO<< "InsertUsers begin.";

    char iCMD[1024] = {0};
    snprintf(iCMD, sizeof(iCMD), "echo \"Chenhd@443420\" | sudo -S sh -c \"useradd -s /bin/bash -d \\\"/home/%s\\\" -m %s; echo \\\"%s:%s\\\"  | chpasswd ; su - %s -c \\\"source /etc/profile\\\"\"\n", in_sUsername, in_sUsername, in_sUsername, in_sPassword, in_sUsername);
    system(iCMD);

    char iSQL[1024] = {0};

    snprintf(iSQL, sizeof(iSQL), "insert into wizard_users (m_username, m_password, m_instance) values ('%s', '%s', '%s')", in_sUsername, in_sPassword, in_sUsername);
    m_oMyDb.ExecuteSQL(iSQL, m_oUsers);

    snprintf(iSQL, sizeof(iSQL), "create database %s;", in_sUsername);
    m_oMyDb.ExecuteSQL(iSQL, m_oUsers);

    snprintf(iSQL, sizeof(iSQL), "create user '%s'@'%%' identified by '%s';", in_sUsername, in_sPassword);
    m_oMyDb.ExecuteSQL(iSQL, m_oUsers);

    snprintf(iSQL, sizeof(iSQL), "grant all on %s.* to %s;", in_sUsername, in_sUsername);
    m_oMyDb.ExecuteSQL(iSQL, m_oUsers);
    
    LOG_INFO<< "InsertUsers end.";
    return 0;
}