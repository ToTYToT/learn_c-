 ///
 /// @file    _Condition.cc
 /// @author  ToTYToT(hongzimeng@foxmail.com)
 /// @date    2016-11-24 22:01:08
 ///
 
#include "_THE_INFO_OF_RUN.h"
#include "_Condition.h"
#include "_MutexLock.h"
namespace T520
{
Condition::Condition(MutexLock &mutex)
:_mutex(mutex)
{
	pthread_cond_init(&_cond,NULL);
}
Condition::~Condition()
{
	pthread_cond_destroy(&_cond);
}
void Condition::wait()
{
	pthread_cond_wait(&_cond,_mutex.getMutexLockPtr());
}
void Condition::notify()
{
	pthread_cond_signal(&_cond);
}
void Condition::notifyAll()
{
	pthread_cond_broadcast(&_cond);
}
}
