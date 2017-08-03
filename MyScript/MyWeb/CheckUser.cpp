#include "CheckUser.h"

int UserCheck::InitializeDb()
{
    m_oMyDb.Initialize((MMyLib::MyDb::DbType)1, "host=127.0.0.1;port=3306;user=root;password=Chenhd@443420;db=mysql");
}

int UserCheck::UninitializeDb()
{
    m_oMyDb.Uninitialize();
}

int UserCheck::UserInputCheck(char* out_sUsername, char* out_sPassword)
{
    do
    {
        char *t_sSignUp = getenv("QUERY_STRING" );
        /*if(!t_sSignUp)
        {
            cout<< "username or password is empty."<< "<br>\n"<< endl;
            break;
        }
        */

        //sscanf(t_sSignUp,"username=%[^&]&password=%s",out_sUsername, out_sPassword);
        
        if((0==strlen(out_sUsername)) || (0==strlen(out_sPassword)))
        {
            cout<< "username or password is empty."<< "<br>\n"<< endl;
            break;
        }

    }while(0);
    return 0;
}

int UserCheck::ExistUsername(char* in_sUsername)
{
    LOG_INFO<< "ExistUsername begin.";

    char iSQL[1024] = {0};
    snprintf(iSQL, sizeof(iSQL), "select m_id, m_username, m_password, m_instance from messi_users where m_username = '%s'", in_sUsername);
    m_oMyDb.ExecuteSQL(iSQL, m_oUsers);
    
    LOG_INFO<< "ExistUsername end.";
    return m_oUsers.size();
}

int UserCheck::ExistUsernamePassword(char* in_sUsername, char* in_sPassword)
{
    LOG_INFO<< "ExistUsernamePassword begin.";

    char iSQL[1024] = {0};
    snprintf(iSQL, sizeof(iSQL), "select m_id, m_username, m_password, m_instance from messi_users where m_username = '%s' and m_password = '%s'", in_sUsername, in_sPassword);
    m_oMyDb.ExecuteSQL(iSQL, m_oUsers);
    
    LOG_INFO<< "ExistUsernamePassword end.";
    return m_oUsers.size();
}

int UserCheck::InsertUsers(char* in_sUsername, char* in_sPassword)
{
    LOG_INFO<< "InsertUsers begin.";

    char iSQL[1024] = {0};

    snprintf(iSQL, sizeof(iSQL), "insert into messi_users (m_username, m_password, m_instance) values ('%s', '%s', '%s')", in_sUsername, in_sPassword, in_sUsername);
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