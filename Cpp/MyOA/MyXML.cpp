#include "MyXML.h"

int main(int argc, char** argv)
{
	// parse an XML document and print the generated SAX events

	if (argc < 2)
	{
		std::cout << "usage: " << argv[0] << ": <xmlfile>" << std::endl;
		return 1;
	}
	
	MyHandler handler;

	SAXParser parser;
	parser.setFeature(XMLReader::FEATURE_NAMESPACES, true);
	parser.setFeature(XMLReader::FEATURE_NAMESPACE_PREFIXES, true);
	parser.setContentHandler(&handler);
	parser.setProperty(XMLReader::PROPERTY_LEXICAL_HANDLER, static_cast<LexicalHandler*>(&handler));
	
	try
	{
		parser.parse(argv[1]);
	}
	catch (Poco::Exception& e)
	{
		std::cerr << e.displayText() << std::endl;
		return 2;
	}
	
	return 0;
}