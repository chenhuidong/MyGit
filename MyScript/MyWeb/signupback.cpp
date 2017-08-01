#include <iostream>   
using namespace std;  
   
int main ()  
{
    //cout<< "Content-type:text/html\n\n";
    if( getenv("QUERY_STRING" ) )
    {
        cout<< getenv("QUERY_STRING" );
    }
    return 0;
}