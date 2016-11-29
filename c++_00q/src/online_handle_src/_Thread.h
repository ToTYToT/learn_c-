 ///
 /// @file    _Thread.h
 /// @author  ToTYToT(hongzimeng@foxmail.com)
 /// @date    2016-11-25 18:03:13
 ///
#ifndef __T_THREAD_H__ 
#define __T_THREAD_H__
#include "_THE_INFO_OF_RUN.h"
#include "_Noncopyable.h"
#include <pthread.h>
#include <functional>
namespace T520
{
class Thread: Noncopyable
{
public:
	typedef std::function<void()> ThreadCallback;
	Thread(ThreadCallback cb);
	~Thread();
	void start();
	void join();
private:
	static void * threadFunc(void *);
private:
	pthread_t _pthId;
	ThreadCallback _cb;
	bool _isRunning;
};
}
#endif
