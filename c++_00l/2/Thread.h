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
#include <functional>
using std::cout;
using std::endl;
using std::function;

namespace wd
{

class Thread : Noncopyable
{
public:
	//Thread();
	typedef function<void()> ThreadCallback;
	Thread(ThreadCallback cb);
	~Thread();
	//virtual ~Thread();

	void start();
	void join();

private:
	static void * threadFunc(void *);

//	virtual void run()=0;
private:
	pthread_t _pthId;
	bool      _isRunning;
	ThreadCallback _cb;
};

}//end of namespace 


#endif 
