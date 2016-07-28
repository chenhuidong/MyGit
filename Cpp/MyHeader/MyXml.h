#ifndef __MY_XML_H_
#define __MY_XML_H_
#include "tinyxml.h"  
#include "tinystr.h"


class MyXml
{
public:
	MyXml(const char * strFileName);
	~MyXml();
	TiXmlElement *m_RootElement;
private:
	TiXmlDocument *m_Document;
};

MyXml::MyXml(const char * strFileName)
{
	m_Document = new TiXmlDocument(strFileName);
	m_Document->LoadFile();
	m_RootElement = m_Document->RootElement(); 
}

MyXml::~MyXml()
{
	delete m_Document;
}

#endif
