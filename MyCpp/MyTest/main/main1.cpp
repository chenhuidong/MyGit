#include <iostream>
#include <string>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>

using namespace std;

int main(int argc, char** argv)
{
    //printf("%d\n", 1);
    char aa[10]={0};
    char bb[10]={'\0'};
    cout<<strlen(aa)<<endl;//0
    cout<<strlen(bb)<<endl;//0

    char cc[10]="jun";
    cout<<strlen(cc)<<endl;//3
    cout<< sizeof(cc)<<endl;//10
    cout<< sizeof(*cc) <<endl;//1

    const char *p = "jun";
    cout << sizeof(*p)<<endl;//1
    cout << sizeof(p) <<endl;//8 指针
    cout << strlen(p) <<endl;//3
    return 0;
}