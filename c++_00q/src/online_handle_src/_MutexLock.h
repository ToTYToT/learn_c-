 ///
 /// @file    _MutexLock.h
 /// @author  ToTYToT(hongzimeng@foxmail.com)
 /// @date    2016-11-25 08:42:56
 ///
#ifndef __T_MUTEXLOCK_H__
#define __T_MUTEXLOCK_H__
#include "_THE_INFO_OF_RUN.h"
#include "_Noncopyable.h"
#include <pthread.h>
namespace T520
{
class MutexLock: Noncopyable
{
public:
	MutexLock();
	~MutexLock();
	void lock();
	void unlock();
	pthread_mutex_t *getMutexLockPtr();
private:
	pthread_mutex_t _mutex;
};
class MutexLockGuard
{
public:
	MutexLockGuard(MutexLock &mutex)
	:_mutex(mutex)
	{
		_mutex.lock();
	}
	~MutexLockGuard()
	{
		_mutex.unlock();
	}
private:
	MutexLock &_mutex;
};
}
#endif
