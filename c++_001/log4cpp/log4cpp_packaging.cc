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
	void destroy();
	void warn(const char *filename,const char *function_name,int num,const char *msg)
	{
        ostringstream oss;
        oss<<filename<<" "<<function_name<<" "<<num<<" "<<msg;
        string msg_tmp=oss.str();
		_infoCat.warn(msg_tmp);
	}
	void error(const char *filename,const char *function_name,int num,const char *msg)
	{
        ostringstream oss;
        oss<<filename<<" "<<function_name<<" "<<num<<" "<<msg;
        string msg_tmp=oss.str();
		_infoCat.error(msg_tmp);
	}
	void debug(const char *filename,const char *function_name,int num,const char *msg)
	{
        ostringstream oss;
        oss<<filename<<" "<<function_name<<" "<<num<<" "<<msg;
        string msg_tmp=oss.str();
		_infoCat.debug(msg_tmp);
	}
	void info(const char *filename,const char *function_name,int num,const char *msg)
	{
        ostringstream oss;
        oss<<filename<<" "<<function_name<<" "<<num<<" "<<msg;
        string msg_tmp=oss.str();
		_infoCat.info(msg_tmp);
	}
	~Mylog();

private:
	Mylog();
private:
    static Mylog * _pInstance;
	Category & _root=Category::getRoot(); 
	Category & _infoCat=_root.getInstance("_infoCat");
	PatternLayout * ptnLy2= new PatternLayout();
	RollingFileAppender * rollingFileApp= new RollingFileAppender("rollingFileApp", 
                    						"my_rollingwd.log",5 * 1024,1);
	PatternLayout * ptnLy3 = new PatternLayout(); 
	OstreamAppender * osAppender= new OstreamAppender("osAppender", &cout); 
};


Mylog::Mylog()

{
#if 1
	ptnLy2->setConversionPattern("%d: %p %c %x: %m%n");
	rollingFileApp->setLayout(ptnLy2);
	_infoCat.addAppender(rollingFileApp);
#endif

#if 1
	ptnLy3->setConversionPattern("%d: %p %c %x: %m%n");
	osAppender->setLayout(ptnLy3);
	_infoCat.addAppender(osAppender);
#endif

	_infoCat.setPriority(Priority::DEBUG);
}

Mylog::~Mylog()
{
    cout<<"Mylog i donot be used"<<endl;
	Category::shutdown();
}
#if 1 
Mylog * Mylog::_pInstance = getInstance();
#endif

#if 1 
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
int Mylogwarn(const char*filename,const char*function_name,unsigned line,const char *msg)
{
	Mylog * p_mylog=Mylog::getInstance();
	p_mylog->warn(filename,function_name,line,msg);
}
#endif

#if 1
int Mylogerror(const char*filename,const char*function_name,unsigned line,const char *msg)
{
	Mylog * p_mylog=Mylog::getInstance();
	p_mylog->error(filename,function_name,line,msg);
}
#endif

#if 1
int Mylogdebug(const char*filename,const char*function_name,unsigned line,const char *msg)
{
	Mylog * p_mylog=Mylog::getInstance();
	p_mylog->debug(filename,function_name,line,msg);
}
#endif

#if 1
int Myloginfo(const char*filename,const char*function_name,unsigned line,const char *msg)
{
	Mylog * p_mylog=Mylog::getInstance();
	p_mylog->info(filename,function_name,line,msg);
}
#endif

#if 1
int main(void)
{
    logWarn("helloworld");
    logDebug("helloworld");
    logInfo("helloworld");
    logError("helloworld");
	Mylog * p_mylog=Mylog::getInstance();
    p_mylog->destroy();
}

#endif
