#include <iostream>
#include <stack>
#include <string>
#include <vector>
#include <map>
using namespace std;

bool testStr(map<char, char>& in_mapDic, string& in_sStr)
{
	stack<char> t_stkChar;
	

	for(int i=0; i<in_sStr.length(); ++i)
	{
		if((!t_stkChar.empty())
			&&(in_mapDic.end()!=in_mapDic.find(in_sStr[i]))
			&&(in_mapDic[in_sStr[i]] == t_stkChar.top()))
		{
			t_stkChar.pop();
		}
		else
		{
			t_stkChar.push(in_sStr[i]);
		}
	}

	if(t_stkChar.empty())
		return true;
	else
		return false;
}

int main()
{
	int t_iStrNum = 0;
	string t_sStr;
	vector<string> t_vecStr;
	bool t_bMatch = true;
	vector<string> t_vecResult;
	map<char, char> t_mapDic;
	t_mapDic.insert(make_pair(']', '['));
	t_mapDic.insert(make_pair(')', '('));

	cin >> t_iStrNum;
	for(int i=0; i<t_iStrNum; ++i)
	{
		cin >> t_sStr;
		t_vecStr.push_back(t_sStr);
	}

	for(vector<string>::iterator it = t_vecStr.begin(); it!= t_vecStr.end(); ++it)
	{
		t_bMatch = testStr(t_mapDic, *it);
		if(t_bMatch)
			t_vecResult.push_back("Yes");
		else
			t_vecResult.push_back("No");
	}

	for(vector<string>::iterator it = t_vecResult.begin(); it!= t_vecResult.end(); ++it)
	{
		cout<< *it<< endl;
	}
	return 0;
}

