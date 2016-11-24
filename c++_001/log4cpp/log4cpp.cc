 ///
 /// @file    log4cpp.cc
 /// @author  lemon(haohb13@gmail.com)
 /// @date    2016-10-22 11:22:42
 ///
 
#include <iostream>
#include <log4cpp/Category.hh>
#include <log4cpp/OstreamAppender.hh>
#include <log4cpp/BasicLayout.hh>
#include <log4cpp/Priority.hh>
using std::cout;
using std::endl;

using namespace log4cpp;

int main(void)
{
	OstreamAppender * osAppender = new OstreamAppender("osApender", &cout);
	osAppender->setLayout(new BasicLayout());

	Category & root = Category::getRoot();
	root.setAppender(osAppender);
	root.setPriority(Priority::ERROR);

	root.error("Hello log4cpp in an Error message!");
	root.warn("Hello log4cpp in a warn message!");

	Category::shutdown();

	return 0;
}

