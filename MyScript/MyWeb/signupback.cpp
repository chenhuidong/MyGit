#include <stdlib.h>
#include <stdio.h>
#include <iostream>
#include "MyDb.h"    
using namespace std;  

int ExistInMysql(char* in_sUsername)
{
    MMyLib::MyDb t_oMyDb;
    t_oMyDb.Initialize((MMyLib::MyDb::DbType)1, "host=127.0.0.1;port=3306;user=chenhuidong;password=Chenhd@443420;db=public");
    
    t_oMyDb.Uninitialize();
    return 0;
}
   
int main(int argc, char* argv[])  
{
    MMyLib::INITIALIZE_LOG(argv[0]);
    cout << "Content-type:text/html\r\n\r\n";  
    cout << "<html>\n"; 
    cout << "<body>\n"; 
    if( getenv("QUERY_STRING" ) )
    {
        char *t_sSignUp = getenv("QUERY_STRING" );
        char t_sUsername[256] = {0};
        char t_sPassword[256] = {0};
        sscanf(t_sSignUp,"username=%[^&]&password=%s",t_sUsername,t_sPassword);

        if(t_sUsername&&t_sPassword)
        {
            ExistInMysql(t_sUsername);
            cout<< "hello,"<< t_sUsername<<". you have signed success." << "<br><br>\n"<< endl;
            cout<< "ssh config:"<< "<br>\n"<< endl;
            cout<< "IP:         124.161.110.68"<< "<br>\n"<< endl;
            cout<< "PORT:       22"<< "<br>\n"<< endl;
            cout<< "USERNAME:   "<< t_sUsername<< "<br>\n"<< endl;
            cout<< "PASSWORD is sign up password."<< "<br>\n"<< endl;
            cout<< "<br>\n"<< endl;
            cout<< "mysql config:"<< "<br>\n"<< endl;
            cout<< "USERNAME:   "<< t_sUsername<< "<br>\n"<< endl;
            cout<< "PASSWORD is sign up password."<< "<br>\n"<< endl;
            cout<< "INSTANCE:   "<< t_sUsername<< "<br>\n"<< endl;
        }
        else
        {
            cout<< "username or password is empty."<< "<br>\n"<< endl;
        }
    }
    cout << "</body>\n";  
    cout << "</html>\n"; 
    return 0;
}