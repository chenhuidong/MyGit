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
        cout<< getenv("QUERY_STRING" );
    }
    cout << "</body>\n";  
    cout << "</html>\n"; 
    return 0;
}