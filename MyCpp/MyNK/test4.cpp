#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <vector>
#include <iostream>
#include <string.h>
using namespace std;

	void replaceSpace(char *str,int length) {
		string a(str);
		//cout << a<< endl;
        for(int i = 0; i< length; i++)
        {
			int begin=a.find(" ");
			//cout << begin<< endl;
			if(begin==-1)
				break;
			else
				a.replace(begin,1,"%20");
				//cout<< a.replace(begin,1,"%20")<< endl;
        }
        //str = (char*)a.c_str();
        sprintf(str, "%s", a.c_str());
        //cout<< str<< endl;
	}

int main()
{
	char buf[256] = "hello world";
	//cout<< strlen(buf)<< endl;
	replaceSpace(buf, strlen(buf));
	//cout<< a.replace(a.find(" "),1,"%20")<< endl;
	cout<< buf<< endl;
	return 0;
}