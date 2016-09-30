#include <iostream>
using namespace std;

int main(int argc, int **argv)
{
	if(argc != 2)
		cout<< "need id"<< endl;

	int t_iConditionId = argv[2];
	//获取id
	cout<< t_iConditionId<< " kkk"<< endl;

	//解析xml
	//执行程序
	return 0;
}