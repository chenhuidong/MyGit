#include "Poco/Logger.h"
#include "Poco/FormattingChannel.h"
#include "Poco/FileChannel.h"
#include "Poco/PatternFormatter.h"
using Poco::Logger;
using Poco::Message;
using Poco::PatternFormatter;
using Poco::FileChannel;
using Poco::FormattingChannel;
using std::string;

//使用Logger向文件写入日志
//FormattingChannel用于格式化输出
//FileChannel设置输出到文件
void FormatLog()
{
	//设置日志输入的格式内容
	FormattingChannel* pFCApp = new FormattingChannel(new PatternFormatter("[%Y-%m-%d %H-%M-%S.%c %N %P %l %s %q ]%t"));
	//设置日志文件的路径
	pFCApp->setChannel(new FileChannel("./mylog.log"));
	//打开channel
	pFCApp->open();

	//获取日志引用
	Logger& logger = Logger::create("FCAppLog",pFCApp,Message::PRIO_INFORMATION);

	logger.information("This is an informational message.");
	logger.warning("This is a warning message");

	pFCApp->close();
}

int main(int argc, char** argv)
{
	//Logger& logger = Logger::get("TestLogger");
	//logger.information("This is an informational message");
	//logger.warning("This is a warning message");
	FormatLog();
	return 0;
}