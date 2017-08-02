#include <stdlib.h>
#include <stdio.h>
#include <iostream>
#include "MyDb.h"
#include "Users.h"    
using namespace std;  

int ExistUsername(char* in_sUsername)
{
    LOG_INFO<< "ExistUsername begin.";
    MMyLib::MyDb t_oMyDb;
    Users t_oUsers;
    t_oMyDb.Initialize((MMyLib::MyDb::DbType)1, "host=127.0.0.1;port=3306;user=chenhuidong;password=Chenhd@443420;db=public");
    
    char iSQL[1024] = {0};
    snprintf(iSQL, sizeof(iSQL), "select m_id, m_username, m_password, m_instance from messi_users where m_username = '%s'", in_sUsername);
    t_oMyDb.ExecuteSQL(iSQL, t_oUsers);
    
    LOG_INFO<< t_oUsers.size()<< endl;
    t_oMyDb.Uninitialize();

    LOG_INFO<< "ExistUsername end.";
    return t_oUsers.size();
}

int ExistUsernamePassword(char* in_sUsername, char* in_sPassword)
{
    LOG_INFO<< "ExistUsernamePassword begin.";
    MMyLib::MyDb t_oMyDb;
    Users t_oUsers;
    t_oMyDb.Initialize((MMyLib::MyDb::DbType)1, "host=127.0.0.1;port=3306;user=chenhuidong;password=Chenhd@443420;db=public");
    
    char iSQL[1024] = {0};
    snprintf(iSQL, sizeof(iSQL), "select m_id, m_username, m_password, m_instance from messi_users where m_username = '%s' and m_password = '%s'", in_sUsername, in_sPassword);
    t_oMyDb.ExecuteSQL(iSQL, t_oUsers);
    
    LOG_INFO<< t_oUsers.size()<< endl;
    t_oMyDb.Uninitialize();

    LOG_INFO<< "ExistUsernamePassword end.";
    return t_oUsers.size();
}

int InsertUsers(char* in_sUsername, char* in_sPassword)
{
    LOG_INFO<< "InsertUsers begin.";
    MMyLib::MyDb t_oMyDb;
    Users t_oUsers;
    t_oMyDb.Initialize((MMyLib::MyDb::DbType)1, "host=127.0.0.1;port=3306;user=chenhuidong;password=Chenhd@443420;db=public");
   
    char iSQL[1024] = {0};
    snprintf(iSQL, sizeof(iSQL), "insert into messi_users (m_username, m_password, m_instance) values ('%s', '%s', '%s')", in_sUsername, in_sPassword, in_sUsername);
    t_oMyDb.ExecuteSQL(iSQL, t_oUsers);

    snprintf(iSQL, sizeof(iSQL), "create database %s;", in_sUsername);
    t_oMyDb.ExecuteSQL(iSQL, t_oUsers);

    t_oMyDb.Uninitialize();
    LOG_INFO<< "InsertUsers end.";
    return 0;
}
   
int main(int argc, char* argv[])  
{
    MMyLib::INITIALIZE_LOG(argv[0]);
    LOG_INFO<< "main begin.";
    char t_sUsername1[256] = {0};
    
    cout << "Content-type:text/html\r\n\r\n";  
    cout << "<html>\n"; 
    cout << "<body>\n"; 
    
    //if( getenv("QUERY_STRING" ) )
    {
        char *t_sSignUp = getenv("QUERY_STRING" );
        char t_sUsername[256] = "chenhd";
        char t_sPassword[256] = "222";
        //sscanf(t_sSignUp,"username=%[^&]&password=%s",t_sUsername,t_sPassword);
        if(t_sUsername&&t_sPassword)
        {
            int t_iUsernameNum = ExistUsername(t_sUsername);
            if(t_iUsernameNum > 0)
            {
                int t_iUserPassNum = ExistUsernamePassword(t_sUsername, t_sPassword);
                if(t_iUserPassNum > 0)
                {
                    cout<< "hello, "<< t_sUsername<<". you have sign in." << "<br><br>\n"<< endl;
                    cout<< "ssh config:"<< "<br>\n"<< endl;
                    cout<< "IP:         124.161.110.68"<< "<br>\n"<< endl;
                    cout<< "PORT:       22"<< "<br>\n"<< endl;
                    cout<< "USERNAME:   "<< t_sUsername<< "<br>\n"<< endl;
                    cout<< "PASSWORD is sign in password."<< "<br>\n"<< endl;
                    cout<< "<br>\n"<< endl;
                    cout<< "mysql config:"<< "<br>\n"<< endl;
                    cout<< "USERNAME:   "<< t_sUsername<< "<br>\n"<< endl;
                    cout<< "PASSWORD is sign in password."<< "<br>\n"<< endl;
                    cout<< "INSTANCE:   "<< t_sUsername<< "<br>\n"<< endl;
                }
                else
                {
                    LOG_INFO<< "your password is wrong."<< endl;
                    cout<< "your password is wrong."<< "<br>\n"<< endl;
                }
            }
            else
            {
                LOG_INFO<< "insert messi_users."<< endl;
                InsertUsers(t_sUsername, t_sPassword);
                cout<< "hello, "<< t_sUsername<<". you have signed up." << "<br><br>\n"<< endl;
                cout<< "ssh config:"<< "<br>\n"<< endl;
                cout<< "IP:         124.161.110.68"<< "<br>\n"<< endl;
                cout<< "PORT:       22"<< "<br>\n"<< endl;
                cout<< "USERNAME:   "<< t_sUsername<< "<br>\n"<< endl;
                cout<< "PASSWORD is sign in password."<< "<br>\n"<< endl;
                cout<< "<br>\n"<< endl;
                cout<< "mysql config:"<< "<br>\n"<< endl;
                cout<< "USERNAME:   "<< t_sUsername<< "<br>\n"<< endl;
                cout<< "PASSWORD is sign in password."<< "<br>\n"<< endl;
                cout<< "INSTANCE:   "<< t_sUsername<< "<br>\n"<< endl;
            }
        }
        else
        {
            cout<< "username or password is empty."<< "<br>\n"<< endl;
        }
    }
    /*else
    {
        cout<< "username or password is empty."<< "<br>\n"<< endl;
    }*/
    
    cout << "</body>\n";  
    cout << "</html>\n"; 
    LOG_INFO<< "main end.";
    return 0;
}