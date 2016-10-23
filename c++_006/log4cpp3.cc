 ///
 /// @file    log4cpp.cc
 /// @author  lemon(haohb13@gmail.com)
 /// @date    2016-10-22 11:22:42
 ///
 
#include <log4cpp/Category.hh>
#include <log4cpp/FileAppender.hh>
#include <log4cpp/RollingFileAppender.hh>
#include <log4cpp/PatternLayout.hh>
#include <log4cpp/Priority.hh>
#include <iostream>
#include <string>
#include <sstream>
using std::cout;
using std::endl;
using std::string;
using std::ostringstream;

using namespace log4cpp;

int main(void)
{
	PatternLayout * ptnLy = new PatternLayout();
	ptnLy->setConversionPattern("%d: %p %c %x: %m%n");

	PatternLayout * ptnLy2 = new PatternLayout();
	ptnLy2->setConversionPattern("%d: %p %c %x: %m%n");

	FileAppender * fileApp = new FileAppender("fileApp", "wd.log");
	fileApp->setLayout(ptnLy);

	RollingFileAppender * rollingFileApp = 
		new RollingFileAppender("rollingFileApp", 
								"rollingwd.log",
								5 * 1024, 
								1);
	rollingFileApp->setLayout(ptnLy2);

	Category & root = Category::getRoot();
	Category & infoCat = root.getInstance("infoCat");
	infoCat.addAppender(fileApp);
	infoCat.addAppender(rollingFileApp);
	infoCat.setPriority(Priority::DEBUG);

	for(int idx = 0; idx != 100; ++idx)
	{
		string errorStr;

		ostringstream oss;
		oss << idx << ": infoCat error message!";
		errorStr = oss.str();
		infoCat.error(errorStr);
	}

	Category::shutdown();

	return 0;
}

