#include <stdlib.h>
#include <stdio.h>
#include <iostream>   
using namespace std;  
   
int main ()  
{
    cout << "Content-type:text/html\r\n\r\n";  
    cout << "<html>\n"; 
    cout << "<body>\n"; 
    if( getenv("QUERY_STRING" ) )
    {
        char *t_sSignUp = getenv("QUERY_STRING" );
        char t_sUsername[256] = {0};
        char t_sPassword[256] = {0};
        sscanf(t_sSignUp,"username=%s&password=%s",&t_sUsername,&t_sPassword);
        cout<< t_sUsername<< endl;
        cout<< t_sPassword<< endl;
    }
    cout << "</body>\n";  
    cout << "</html>\n"; 
    return 0;
}