#include "MyFactoryFactory.h"

//单件
static Poco::SingletonHolder<MyFactoryFactory> holder;

MyFactoryFactory& MyFactoryFactory::DefaultFFactory()
{
    return *holder.get();
}

MyFactoryFactory::MyFactoryFactory()
{
    //注册子类
    m_oFFactory.registerClass<MyDealFactory>("MyDealFactory");
    std::cout<< "MyFactoryFactory"<< std::endl;  
}

MyFactoryFactory::~MyFactoryFactory()
{
	for(std::map<std::string, Factory*>::iterator it=m_mFFactory.begin(); it!=m_mFFactory.end();++it)
	{
		//std::cout<< it->first<< " end"<< std::endl;
		delete it->second;
	}
    std::cout<< "~MyFactoryFactory"<< std::endl; 
}

int MyFactoryFactory::CreateAllFactory()
{
    //创建子类实例
    m_mFFactory.insert(std::make_pair("MyDealFactory", m_oFFactory.createInstance("MyDealFactory")));
    return 0;
}

Factory* MyFactoryFactory::getFactory(const std::string& in_sFactoryName)
{
    return m_mFFactory[in_sFactoryName];
}