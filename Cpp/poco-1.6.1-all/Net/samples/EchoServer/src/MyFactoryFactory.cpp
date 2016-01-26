#include "MyFactoryFactory.h"

MyFactoryFactory::MyFactoryFactory()
{
    //注册子类
    m_oFFactory.registerClass<MyDealFactory>("MyDealFactory");  
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