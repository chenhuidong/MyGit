#include "../../../stdafx.h"
#include "../../../MyXml.h"

int main()
{
	//TiXmlDocument *myDocument = new TiXmlDocument("test.xml");
	MyXml oMyXml("test.xml");

	//获得第一个Person节点。  
    TiXmlElement *FirstPerson = oMyXml.m_RootElement->FirstChildElement();  
    cout << FirstPerson->Value() << endl;  
    TiXmlElement *NameElement = FirstPerson->FirstChildElement(); 
    cout << NameElement->Value()<< " " <<NameElement->FirstChild()->Value() << endl;   
	return 0;
}