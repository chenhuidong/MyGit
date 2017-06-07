#ifndef _MYPOKER_DISPACH_CARD_H_
#define _MYPOKER_DISPACH_CARD_H_
namespace mypoker
{
	class DispachCard
	{
	public:
		DispachCard(int* in_pFd):m_pFd(in_pFd){};
		~DispachCard(){};
		int Dispach();
	private:
		int* m_pFd;
	};
};
#endif