 ///
 /// @file    _Thread.cc
 /// @author  ToTYToT(hongzimeng@foxmail.com)
 /// @date    2016-11-25 18:07:37
 ///
#include "_Thread.h" 
#include "_THE_INFO_OF_RUN.h"
namespace T520
{
Thread::Thread(ThreadCallback cb)
:_pthId(0)
,_cb(cb)
,_isRunning(false)
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
	pthread_create(&_pthId,NULL,&Thread::threadFunc,this);
	_isRunning=true;
}
void Thread::join()
{
	THE_INFO_OF_RUN;
	if(_isRunning)
	{
		pthread_join(_pthId,NULL);
	}
}
void * Thread::threadFunc(void *arg)
{
	THE_INFO_OF_RUN;
	Thread * pthread=static_cast<Thread*>(arg);
	if(pthread)
		pthread->_cb();
	return NULL;
}
}
