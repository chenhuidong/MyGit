#include "MyDealFactory.h"
Factory::Factory()
{
	std::cout<< "Factory"<< std::endl; 
}

Factory::~Factory()
{
	std::cout<< "~Factory"<< std::endl; 
}

MyDealFactory::MyDealFactory()
{
	std::cout<< "MyDealFactory"<< std::endl; 
}

MyDealFactory::~MyDealFactory()
{
	for(std::map<std::string, MyDealBase*>::iterator it=m_mMyDealBase.begin(); it!=m_mMyDealBase.end(); ++it)
	{
		delete it->second;
	}
	std::cout<< "~MyDealFactory"<< std::endl; 
}

int MyDealFactory::Initialize()
{
	//注册子类
	m_oDFactory.registerClass<MyDeal1>("MyDeal1");  
    m_oDFactory.registerClass<MyDeal2>("MyDeal2");  
	return 0;
}

MyDealBase* MyDealFactory::CreateInstance(const std::string& in_sDealName)
{
	//创建子类实例
	assert (m_oDFactory.isClass(in_sDealName));  
	MyDealBase* t_pMyDealBase = m_oDFactory.createInstance(in_sDealName);
	m_mMyDealBase.insert(std::make_pair(in_sDealName, t_pMyDealBase));
	return t_pMyDealBase;
}

