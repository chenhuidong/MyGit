#include "tinyxml.h"  
#include "tinystr.h"  
  
#include <iostream>  
  
using namespace std;  
  
int main()  
{  
    //创建一个XML的文档对象。  
    TiXmlDocument *myDocument = new TiXmlDocument("test.xml");  
    myDocument->LoadFile();  
      
    //获得根元素，即Persons。  
    TiXmlElement *RootElement = myDocument->RootElement();  
  
    //输出根元素名称，即输出Persons。  
    cout << RootElement->Value() << endl;  
      
    //获得第一个Person节点。  
    TiXmlElement *FirstPerson = RootElement->FirstChildElement();  
    //输出接点名Person  
  
    cout << FirstPerson->Value() << endl;  
    //获得第一个Person的name节点和age节点和ID属性。  
    TiXmlElement *NameElement = FirstPerson->FirstChildElement();  
    TiXmlElement *AgeElement = NameElement->NextSiblingElement();  
    TiXmlElement *SexElement = NameElement->NextSiblingElement();  
    TiXmlAttribute *IDAttribute = FirstPerson->FirstAttribute();  
      
    //输出第一个Person的name内容，即周星星；age内容，即20；ID属性，即1。  
    cout << NameElement->FirstChild()->Value() << endl;  
    cout << AgeElement->FirstChild()->Value() << endl;  
    cout << SexElement->FirstChild()->Value() << endl; 
    cout << IDAttribute->Value() << endl;  
  
    return 0;  
} 