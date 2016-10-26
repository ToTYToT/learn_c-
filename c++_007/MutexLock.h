 ///
 /// @file    MutexLock.h
 /// @author  lemon(haohb13@gmail.com)
 /// @date    2016-10-24 10:33:30
 ///


// 防止重复定义的
#ifndef __WANGDAO_MUTEXLOCK_H__
#define __WANGDAO_MUTEXLOCK_H__

 
#include <pthread.h>
#include <iostream>
using std::cout;
using std::endl;

class MutexLock
{
public:
	MutexLock();
	~MutexLock();

	void lock();
	void unlock();

	pthread_mutex_t * getMutexLockPtr()
	{	return &_mutex;	}
private:
	pthread_mutex_t _mutex;
};


#endif
