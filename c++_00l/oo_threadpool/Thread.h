 ///
 /// @file    Thread.h
 /// @author  lemon(haohb13@gmail.com)
 /// @date    2016-11-15 10:57:56
 ///
 
#ifndef __WANGDAO_THREAD_H__
#define __WANGDAO_THREAD_H__

#include "Noncopyable.h"

#include <pthread.h>
#include <iostream>
using std::cout;
using std::endl;


namespace wd
{

class Thread : Noncopyable
{
public:
	Thread();

	virtual ~Thread();

	void start();
	void join();

private:
	static void * threadFunc(void *);

	virtual void run()=0;
private:
	pthread_t _pthId;
	bool      _isRunning;
};

}//end of namespace 


#endif 
