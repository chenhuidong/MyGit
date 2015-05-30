#ifndef __MY_XML_H_
#define __MY_XML_H_
#include "tinyxml.h"  
#include "tinystr.h"


class MyXml
{
public:
	MyXml(const char * strFileName)
	{
		m_Document = new TiXmlDocument("test.xml");
		m_Document.LoadFile();
	}
private:
	TiXmlDocument *m_Document;
	TiXmlElement *m_RootElement;
};

#endif
