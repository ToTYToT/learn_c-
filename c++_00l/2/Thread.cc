 ///
 /// @file    Thread.cc
 /// @author  lemon(haohb13@gmail.com)
 /// @date    2016-11-15 10:27:50
 ///
 
#include "Thread.h"

#define THE_INFO_OF_RUN (std::cout<<"    FILE:"<<__FILE__<<"    function:"<<__func__<<"    LINE:"<<__LINE__<<endl)

namespace wd
{

//Thread::Thread()
Thread::Thread(ThreadCallback cb)
: _pthId(0)
,_cb(cb)
, _isRunning(false)
{
        THE_INFO_OF_RUN;
}

Thread::~Thread()
{
        THE_INFO_OF_RUN;
	if(_isRunning)
	{
		pthread_detach(_pthId);
	}
}

void Thread::start()
{
        THE_INFO_OF_RUN;
	pthread_create(&_pthId, NULL, 
					&Thread::threadFunc, this);
	_isRunning = true;
}

void Thread::join()
{
        THE_INFO_OF_RUN;
	if(_isRunning){
		pthread_join(_pthId, NULL);
	}
}

void * Thread::threadFunc(void * arg)
{
        THE_INFO_OF_RUN;
	Thread * pthread = static_cast<Thread*>(arg);
	if(pthread)
//		pthread->run();
		pthread->_cb();
	return NULL;
}


}//end of namespace wd
