#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <vector>
#include <iostream>
using namespace std;

bool Find(int target, vector<vector<int> > array) {
    int a = array.size();
    int b = (*array.begin()).size();
    cout<< a<< " "<< b<< endl;
    for(int i=0; i<b; i++)
    {
        for(int j=0;j<a; j++)
        {
            if(array[j][i] == target)
            {
                return true;
            }
        }
    }
    return false;
}

int main()
{
    vector<vector<int> > a;
    vector<int> b;
    b.push_back(1);
    b.push_back(2);
    b.push_back(3);
    b.push_back(4);
    a.push_back(b);

    vector<int> b1;
    b1.push_back(6);
    b1.push_back(8);
    b1.push_back(10);
    b1.push_back(12);
    a.push_back(b1);

    vector<int> b2;
    b2.push_back(15);
    b2.push_back(39);
    b2.push_back(55);
    b2.push_back(101);
    a.push_back(b2);

    //cout<< a[1][0] << endl;
    cout<<Find(39, a)<<endl;
}