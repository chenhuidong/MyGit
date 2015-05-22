// testSTLPort521.cpp : Defines the entry point for the console application.
//
#include "../../stdafx.h"
#include <iostream>
#include <hash_map>
#include <string>

using namespace std;

int main()
{
    hash_map<int, string> mymap;
    mymap[0x2011] = "liuxuezong";
    mymap[0x7c00] = "STLport";
    mymap[0x9000] = "hello hash_map!";
    hash_map<int, string>::iterator iter = mymap.find(0x9000);
    if (iter != mymap.end())
    {
        cout << iter->second << endl;
    }
    return 0;
}

