 ///
 /// @file    _Condition.h
 /// @author  ToTYToT(hongzimeng@foxmail.com)
 /// @date    2016-11-24 22:04:15
 ///
#ifndef __T_CONDITION_H__
#define __T_CONDITION_H__
#include "_THE_INFO_OF_RUN.h"
#include "_Noncopyable.h"
#include <pthread.h>
namespace T520
{
class MutexLock;
class Condition: Noncopyable
{
public:
	Condition(MutexLock &mutex);
	~Condition();
	void wait();
	void notify();
	void notifyAll();
private:
	pthread_cond_t _cond;
	MutexLock &_mutex;
};
}
#endif
