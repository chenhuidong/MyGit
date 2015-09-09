#ifndef __MY_OA_MY_XML_H_
#define __MY_OA_MY_XML_H_

#include "Poco/SAX/SAXParser.h"
#include "Poco/SAX/ContentHandler.h"
#include "Poco/SAX/LexicalHandler.h"
#include "Poco/SAX/Attributes.h"
#include "Poco/SAX/Locator.h"
#include "Poco/Exception.h"
#include <iostream>

using Poco::XML::SAXParser;
using Poco::XML::XMLReader;
using Poco::XML::XMLString;
using Poco::XML::XMLChar;
using Poco::XML::ContentHandler;
using Poco::XML::LexicalHandler;
using Poco::XML::Attributes;
using Poco::XML::Locator;

class MyHandler: public ContentHandler, public LexicalHandler
{
public:
	MyHandler():
		_pLocator(0)
	{
	}
	
	// ContentHandler
	void setDocumentLocator(const Locator* loc)
	{
		_pLocator = loc;
	}
	
	void startDocument()
	{
		where("startDocument");
	}
	
	void endDocument()
	{
		where("endDocument");
	}
	
	void startElement(const XMLString& uri, const XMLString& localName, const XMLString& qname, const Attributes& attributes)
	{
		where("startElement");
		std::cout << "uri:       " << uri << std::endl
		          << "localName: " << localName << std::endl
		          << "qname:     " << qname << std::endl;
		std::cout << "Attributes: " << std::endl;
		for (int i = 0; i < attributes.getLength(); ++i)
		{
			std::cout << attributes.getLocalName(i) << "=" << attributes.getValue(i) << std::endl;
		}
	}
	
	void endElement(const XMLString& uri, const XMLString& localName, const XMLString& qname)
	{
		where("endElement");
	}
	
protected:
	void where(const std::string& meth)
	{
		std::cout << "*** " << meth;
		if (_pLocator)
		{
			std::cout << " in "
			          << _pLocator->getSystemId()
			          << ", line " << _pLocator->getLineNumber() 
			          << ", col " << _pLocator->getColumnNumber() 
			          << std::endl;
		}
	}
	
private:
	const Locator* _pLocator;
};

#endif