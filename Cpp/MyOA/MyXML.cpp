#include "MyXML.h"

int main(int argc, char** argv)
{
	// Parse an XML document from standard input
	// and use a NodeIterator to print out all nodes.
	
	InputSource src("/mnt/home2/51linux_LxomB0aQ/MyProgram/MyGit/Cpp/Poco/XML/sample.xml");
	try
	{
		DOMParser parser;
		AutoPtr<Document> pDoc = parser.parse(&src);
		
		NodeIterator it(pDoc, NodeFilter::SHOW_ALL);
		/*Node* pNode = it.nextNode();
		while (pNode)
		{
			std::cout << pNode->nodeName() << ":" << pNode->nodeValue() << std::endl;
			pNode = it.nextNode();
		}*/
		Node* pNode = it.firstChild();
		std::cout << pNode->nodeName() << ":" << pNode->nodeValue() << std::endl;
	}
	catch (Exception& exc)
	{
		std::cerr << exc.displayText() << std::endl;
	}
	
	return 0;
}