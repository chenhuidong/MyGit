#include <bitset>
#include <iostream>
#include <string>

using namespace std;

int main(int argc, char** argv)
{
	string s("1100");
	bitset<10> bitvec(s);
	cout<< bitvec<< endl;
	return 0;
}