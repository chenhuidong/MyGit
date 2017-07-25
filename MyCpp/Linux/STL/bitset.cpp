#include <bitset>
#include <iostream>
#include <string>

using namespace std;

int main(int argc, char** argv)
{
	string s("1100");
	bitset<5> bitvec(s);
	cout<< bitvec<< " "<< bitvec.size()<< " "<< bitvec.count()<< endl;

	bitvec[3] = 0;
	cout<< bitvec<< " "<< bitvec.size()<< " "<< bitvec.count()<< endl;

	bitvec |= 1UL << 3; 
	cout<< bitvec<< " "<< bitvec.size()<< " "<< bitvec.count()<< endl; 

	bitset<16> bitvec2(0xff);
	cout<< bitvec2<< endl;

	bitvec2.set(15);
	cout<< bitvec2<< endl; 

	return 0;
}