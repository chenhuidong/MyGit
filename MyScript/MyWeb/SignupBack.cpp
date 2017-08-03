#include <stdlib.h>
#include <stdio.h>
#include <iostream> 
#include "MyStdAfx.h"
#include "CheckUser.h"   
using namespace std;  

int main(int argc, char* argv[])  
{
    MMyLib::INITIALIZE_LOG(argv[0]);
    LOG_INFO<< "main begin.";
    
    cout << "Content-type:text/html\r\n\r\n";  
    cout << "<html>\n"; 
    cout << "<body>\n";

    int t_iReturn = 0;
    UserCheck t_oUserCheck;
    t_oUserCheck.InitializeDb();

    do
    {
        char t_sUsername[256] = "chenhd";
        char t_sPassword[256] = "234";
        t_iReturn = t_oUserCheck.UserInputCheck(t_sUsername, t_sPassword);
        if(0 != t_iReturn)
            break;

        int t_iUsernameNum = t_oUserCheck.ExistUsername(t_sUsername);
        if(t_iUsernameNum > 0)
        {
            int t_iUserPassNum = t_oUserCheck.ExistUsernamePassword(t_sUsername, t_sPassword);
            if(t_iUserPassNum > 0)
            {
                cout<< "hello, "<< t_sUsername<<". you have sign in." << "<br><br>\n"<< endl;
            }
            else
            {
                LOG_INFO<< "your password is wrong."<< endl;
                cout<< "your password is wrong."<< "<br>\n"<< endl;
                break;
            }
        }
        else
        {
            LOG_INFO<< "insert messi_users."<< endl;
            t_oUserCheck.InsertUsers(t_sUsername, t_sPassword);
            cout<< "hello, "<< t_sUsername<<". you have signed up." << "<br><br>\n"<< endl;
        }
        cout<< "ssh config:"<< "<br>\n"<< endl;
        cout<< "IP:         124.161.110.68"<< "<br>\n"<< endl;
        cout<< "PORT:       10302"<< "<br>\n"<< endl;
        cout<< "USERNAME:   "<< t_sUsername<< "<br>\n"<< endl;
        cout<< "PASSWORD is sign in password."<< "<br>\n"<< endl;
        cout<< "<br>\n"<< endl;
        cout<< "mysql config:"<< "<br>\n"<< endl;
        cout<< "USERNAME:   "<< t_sUsername<< "<br>\n"<< endl;
        cout<< "PASSWORD is sign in password."<< "<br>\n"<< endl;
        cout<< "INSTANCE:   "<< t_sUsername<< "<br>\n"<< endl;    
    }while(0);

    t_oUserCheck.UninitializeDb(); 

    cout << "</body>\n";  
    cout << "</html>\n"; 
    LOG_INFO<< "main end.";
    return 0;
}