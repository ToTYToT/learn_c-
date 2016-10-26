 ///
 /// @file    log4cpp_packaging.cc
 /// @author  ToTYToT(hongzimeng@foxmail.com)
 /// @date    2016-10-22 16:17:27
 ///
#include "log4cpp_packaging.h" 

using std::cout;
using std::endl;
using std::string;
using std::ostringstream;

using namespace log4cpp;

class Mylog
{
public:
	static Mylog * getInstance()
	{
		if(NULL == _pInstance)
		{
			_pInstance = new Mylog;
		}
		return _pInstance;
	}
	//void destroy();
	void warn(const char *filename,const char *function_name,int num,const char *msg)
	{
        ostringstream oss;
        oss<<filename<<" "<<function_name<<" "<<num<<" "<<msg;
        string msg_tmp=oss.str();
		_infoCat.warn(msg_tmp);
	}
	~Mylog();

private:
	Mylog();
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
    delete _pInstance;
	Category::shutdown();
}
#if 1 
Mylog * Mylog::_pInstance = getInstance();
#endif

#if 0
void Mylog::destroy()
{
    if(_pInstance)
        delete _pInstance;
}
#endif 
#if 0
Mylog * Mylog::_pInstance =NULL; 
#endif

#if 1
int Mylogwarn(void)
{
	Mylog * p_mylog=Mylog::getInstance();
	logWarn("Message_use_define");
	p_mylog->warn(__FILE__,__func__,115,"hello_20161023");
	//delete p_mylog;
    //p_mylog->destroy();
}
#endif

#if 1
int main(void)
{
    Mylogwarn();
    Mylogwarn();
    Mylogwarn();
    Mylogwarn();
}

#endif
