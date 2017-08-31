#include <log4cpp/Category.hh>
#include <log4cpp/PropertyConfigurator.hh>

int main(int argc, char* argv[])
{
	std::string initFileName = "log4cpp.properties";
	log4cpp::PropertyConfigurator::configure(initFileName);
	log4cpp::Category& root = log4cpp::Category::getRoot();

	root.warn("Storm is coming");
	root.info("Ready for storm.");

	log4cpp::Category::shutdown();
	return 0;
}