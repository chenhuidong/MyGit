#include "MyBaseFunc.h"

string MMyLib::itoa(int32	i)
{
	char buf[256];
	snprintf(buf, 256, "%d", i);
	string	ret = buf;
	return ret;
}

string MMyLib::itoa(int64	i)
{
	char	buf[256];
	buf[0] = '+';
	if ( i == 0 )
	{
		buf[1] = '0';
		buf[2] = 0;
	}
	else {
		int idx = 1;
		if ( i < 0 )
		{
			buf[0] = '-';
			i = -i;
		}
		for ( ; i != 0; i /= 10 )
		{
			buf[idx++] = '0' + (i % 10);
		}
		for ( int j = 1, k = idx - 1; j < k; j++, k-- )
		{
			char c = buf[j];
			buf[j] = buf[k];
			buf[k] = c;
		}
		buf[idx] = 0;
	}
	return string(buf[0] == '-' ? buf : buf + 1);
}

int64 MMyLib::atol64(const char * szStr)
{
	int64 n = 0;
	bool bNegative(false);
	for ( ; *szStr && isspace(*szStr); ++szStr );
	if ( *szStr == '-' )
	{
		bNegative = true;
		szStr++;
	}
	for ( ; *szStr >= '0' && *szStr <= '9'; ++szStr )
	{
		n = n * 10 + (*szStr - '0');
	}
	return ( bNegative ) ? -n : n;
}

string& MMyLib::toUpper(string& in_str)
{
	int32 i = in_str.size();
	string::iterator itr = in_str.begin();
	while ( i-- ) 
	{
		(*itr) = (unsigned char)toupper((unsigned char)(*itr));
		itr++;
	}
	return in_str;
}

string& MMyLib::toLower(string& in_str)
{
	int32 i = in_str.size();
	string::iterator itr = in_str.begin();
	while ( i-- ) 
	{
		(*itr) = (unsigned char)tolower((unsigned char)(*itr));
		itr++;
	}
	return in_str;
}

string& MMyLib::ltrim(string &str) {
    string::iterator p = find_if(str.begin(), str.end(), not1(ptr_fun<int, int>(isspace)));
    str.erase(str.begin(), p);
    return str;
}
 
string& MMyLib::rtrim(string &str) {
    string::reverse_iterator p = find_if(str.rbegin(), str.rend(), not1(ptr_fun<int , int>(isspace)));
    str.erase(p.base(), str.end());
    return str;
}
 
string& MMyLib::trim(string &str) {
    ltrim(rtrim(str));
    return str;
}
