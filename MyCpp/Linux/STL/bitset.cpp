#include <bitset>
#include <iostream>
#include <string>

using namespace std;

int main(int argc, char** argv)
{
	string s("1100");
	bitset<5> bitvec(s);
	cout<< bitvec<< endl;

	bitset<16> bitvec2(0xff);
	cout<< bitvec2<< endl;

	bitvec2.set(20);
	cout<< bitvec2<< endl; 
	return 0;
}