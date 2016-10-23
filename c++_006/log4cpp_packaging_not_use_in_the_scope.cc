 ///
 /// @file    log4cpp_packaging.cc
 /// @author  ToTYToT(hongzimeng@foxmail.com)
 /// @date    2016-10-22 16:17:27
 ///
#include "log4cpp_mylog.h" 
#if 0
#include <log4cpp/Category.hh>
#include <log4cpp/FileAppender.hh>
#include <log4cpp/RollingFileAppender.hh>
#include <log4cpp/PatternLayout.hh>
#include <log4cpp/Priority.hh>
#include <log4cpp/OstreamAppender.hh>
#include <iostream>
#include <string>
#include <sstream>

#define logWarn(msg)  p_mylog->warn(__FILE__,__func__,__LINE__,msg)
#endif

using std::cout;
using std::endl;
using std::string;
using std::ostringstream;

using namespace log4cpp;

class Mylog
{
public:
	//static Mylog * getInstance()
	static Mylog * getInstance()
	{
		if(NULL == _pInstance)
		{
			_pInstance = new Mylog;
		}
		return _pInstance;
	}

	//static void destroy()
	void destroy()
	{
		if(_pInstance)
			delete _pInstance;
	}
	void warn(const char *filename,const char *function_name,int num,const char *msg)
	{
        ostringstream oss;
        oss<<filename<<" "<<function_name<<" "<<num<<" "<<msg;
        string msg_tmp=oss.str();
		_infoCat.warn(msg_tmp);
	}

private:
	Mylog();
	

	~Mylog();
private:
	static Mylog * _pInstance;
	Category & root = Category::getRoot();
	Category & _infoCat= root.getInstance("_infoCat");
	//Category & _infoCat;
};


Mylog::Mylog()
{
#if 0
	PatternLayout * ptnLy = new PatternLayout();
	ptnLy->setConversionPattern("%d: %p %c %x: %m%n");
	FileAppender * fileApp = new FileAppender("fileApp", "my_wd.log");
	fileApp->setLayout(ptnLy);
	_infoCat.addAppender(fileApp);
#endif

#if 1
	PatternLayout * ptnLy2 = new PatternLayout();
	ptnLy2->setConversionPattern("%d: %p %c %x: %m%n");
	RollingFileAppender * rollingFileApp = 
		new RollingFileAppender("rollingFileApp", 
								"my_rollingwd.log",
								5 * 1024, 
								1);
	rollingFileApp->setLayout(ptnLy2);
	_infoCat.addAppender(rollingFileApp);
#endif

#if 1
	PatternLayout * ptnLy3 = new PatternLayout();
	ptnLy3->setConversionPattern("%d: %p %c %x: %m%n");
	OstreamAppender * osAppender = new OstreamAppender("osApender", &cout);
	osAppender->setLayout(ptnLy3);
	_infoCat.addAppender(osAppender);
#endif

	_infoCat.setPriority(Priority::DEBUG);
}

Mylog::~Mylog()
{
	Category::shutdown();
}

//Mylog * Mylog::_pInstance = getInstance();
Mylog * Mylog::_pInstance =NULL; 

#if 1
int main(void)
{
	Mylog * p_mylog=Mylog::getInstance();
	logWarn("Message_use_define");
	//p_mylog->warn(__FILE__,__func__,115,"hello_20161023");
	p_mylog->destroy();
}
#endif
