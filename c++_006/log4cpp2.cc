 ///
 /// @file    log4cpp.cc
 /// @author  lemon(haohb13@gmail.com)
 /// @date    2016-10-22 11:22:42
 ///
 
#include <iostream>
#include <log4cpp/Category.hh>
#include <log4cpp/OstreamAppender.hh>
#include <log4cpp/PatternLayout.hh>
#include <log4cpp/Priority.hh>
using std::cout;
using std::endl;

using namespace log4cpp;

int main(void)
{
	PatternLayout * ptnLy = new PatternLayout();
	ptnLy->setConversionPattern("%d: %p %c %x: %m%n");

	OstreamAppender * osAppender = new OstreamAppender("osApender", &cout);
	osAppender->setLayout(ptnLy);

	Category & root = Category::getRoot();
	Category & infoCat = root.getInstance("infoCat");
	infoCat.setAppender(osAppender);
	infoCat.setPriority(Priority::INFO);

	
	infoCat.info("system is running");
	infoCat.warn("Hello log4cpp in a warn message!");
	infoCat.error("Hello log4cpp in an errormessage!");
	infoCat.fatal("fatal message");

	Category::shutdown();

	return 0;
}

