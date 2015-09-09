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
	}
	
	void endDocument()
	{
	}
	
	void startElement(const XMLString& uri, const XMLString& localName, const XMLString& qname, const Attributes& attributes)
	{
		where("startElement");
		std::cout << "localName: " << localName << std::endl
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
	
	void characters(const XMLChar ch[], int start, int length)
	{
	}
	
	void ignorableWhitespace(const XMLChar ch[], int start, int length)
	{
	}
	
	void processingInstruction(const XMLString& target, const XMLString& data)
	{
	}
	
	void startPrefixMapping(const XMLString& prefix, const XMLString& uri)
	{
	}
	
	void endPrefixMapping(const XMLString& prefix)
	{
	}
	
	void skippedEntity(const XMLString& name)
	{
	}
	
	// LexicalHandler
	void startDTD(const XMLString& name, const XMLString& publicId, const XMLString& systemId)
	{
	}
	
	void endDTD()
	{
	}
	
	void startEntity(const XMLString& name)
	{
	}
	
	void endEntity(const XMLString& name)
	{
	}
	
	void startCDATA()
	{
	}
	
	void endCDATA()
	{
	}
	
	void comment(const XMLChar ch[], int start, int length)
	{
	}

protected:
	void where(const std::string& meth)
	{
		std::cout << "*** " << meth<< std::endl;
	}

private:
	const Locator* _pLocator;
};

#endif