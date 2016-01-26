#include "MyFactoryFactory.h"

MyFactoryFactory::MyFactoryFactory()
{
    //注册子类
    m_oFFactory.registerClass<MyDealFactory>("MyDealFactory");  
}

int MyFactoryFactory::CreateAllFactory()
{
    //创建子类实例
    m_pMyDealFactory = dynamic_cast<MyDealFactory*>(m_oFFactory.createInstance("MyDealFactory"));
    return 0;
}

int MyFactoryFactory::InitializeAllFactory()
{
    m_pMyDealFactory->Initialize();
    return 0;
}

MyDealFactory* MyFactoryFactory::getMyDealFactory()
{
    return m_pMyDealFactory;
}
