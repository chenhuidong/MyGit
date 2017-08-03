#include <stdlib.h>
#include <stdio.h>
#include <iostream> 
#include "MyStdAfx.h"   
using namespace std;  

int main(int argc, char* argv[])  
{
    MMyLib::INITIALIZE_LOG(argv[0]);
    LOG_INFO<< "main begin.";
    
    cout << "Content-type:text/html\r\n\r\n";  
    cout << "<html>\n"; 
    cout << "<body>\n"; 
    do
    {
        //if( getenv("QUERY_STRING" ) )
        {
            char *t_sSignUp = getenv("QUERY_STRING" );
            char t_sUsername[256] = {0};
            char t_sPassword[256] = {0};
            sscanf(t_sSignUp,"username=%[^&]&password=%s",t_sUsername,t_sPassword);
            if((0==strlen(t_sUsername)) || (0==strlen(t_sPassword)))
            {
                cout<< "username or password is empty."<< "<br>\n"<< endl;
                break;
            }

            //if(t_sUsername)

                int t_iUsernameNum = ExistUsername(t_sUsername);
                if(t_iUsernameNum > 0)
                {
                    int t_iUserPassNum = ExistUsernamePassword(t_sUsername, t_sPassword);
                    if(t_iUserPassNum > 0)
                    {
                        cout<< "hello, "<< t_sUsername<<". you have sign in." << "<br><br>\n"<< endl;
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
        /*else
        {
            cout<< "username or password is empty."<< "<br>\n"<< endl;
        }*/
    }while(0);
    cout << "</body>\n";  
    cout << "</html>\n"; 
    LOG_INFO<< "main end.";
    return 0;
}