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
	FormattingChannel* pFC = new FormattingChannel(new PatternFormatter("[%Y-%m-%d %H-%M-%S.%c %P %s %p] %t"));
	//设置日志文件的路径
	pFC->setChannel(new FileChannel("./testlog.log"));
	//打开channel
	pFC->open();

	//获取日志引用
	Logger& logger = Logger::create("testlog", pFC, Message::PRIO_INFORMATION);

	logger.information("This is an informational message.");
	logger.warning("This is a warning message");

	pFC->close();
}

int main(int argc, char** argv)
{
	FormatLog();
	return 0;
}