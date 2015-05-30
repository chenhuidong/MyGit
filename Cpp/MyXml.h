#ifndef __MY_XML_H_
#define __MY_XML_H_
#include "tinyxml.h"  
#include "tinystr.h"

class MyXml
{
public:
	MyXml(char * strFileName):m_Document(strFileName)
	{
		m_Document.LoadFile();
	}
private:
	TiXmlDocument m_Document;
	TiXmlElement m_RootElement;
};

#endif
