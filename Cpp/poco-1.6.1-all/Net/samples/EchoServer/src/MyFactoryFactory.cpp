#include "MyFactoryFactory.h"

//单件
static Poco::SingletonHolder<MyFactoryFactory> MyFactoryFactoryHolder;

MyFactoryFactory& MyFactoryFactory::DefaultFFactory()
{
    return *MyFactoryFactoryHolder.get();
}

MyFactoryFactory::MyFactoryFactory()
{
    //注册子类
    m_oFFactory.registerClass<MyDealFactory>("MyDealFactory");
}

MyFactoryFactory::~MyFactoryFactory()
{
	for(std::map<std::string, Factory*>::iterator it=m_mFFactory.begin(); it!=m_mFFactory.end();++it)
	{
		//std::cout<< it->first<< " end"<< std::endl;
		delete it->second;
	}
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