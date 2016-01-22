#include "MyFactoryFactory.h"
/*
MyFactoryAdapter::MyFactoryAdapter()
{
    m_sClassName = "";
    m_oMyDealFactory.InitializeDFactory();
    //m_oMyDealFactory1.InitializeDFactory();
}

int MyFactoryAdapter::Deal()
{	    
    if(std::strcmp(m_sClassName, "MyDeal1") == 0 ||
        std::strcmp(m_sClassName, "MyDeal2") == 0)
    {
        m_oMyDealFactory.CreateInstance(m_sClassName))->DealTransaction();
    }
    //else if(std::strcmp(m_sClassName, "MyDeal3") == 0)
    //{
    //  m_oMyDealFactory1.CreateInstance(m_sClassName))->D();
    //}
    else
    {
        return -1;
    }
    
	return 0;
}


void MyFactoryAdapter::setClassName(const std::string &in_sClassName)
{
    m_sClassName = in_sClassName;
}

const std::string& MyFactoryAdapter::getClassName()
{
    return m_sClassName;
}
*/

MyFactoryFactory::MyFactoryFactory()
{
    //注册子类
    m_oFFactory.registerClass<MyDealFactory>("MyDealFactory");  
}

int MyFactoryFactory::CreateAllInstance()
{
    //创建子类实例
    m_pMyDealFactory = dynamic_cast<MyDealFactory*>(m_oFFactory.createInstance("MyDealFactory"));
    return 0;
}