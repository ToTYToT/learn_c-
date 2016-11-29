 ///
 /// @file    _MutexLock.cc
 /// @author  ToTYToT(hongzimeng@foxmail.com)
 /// @date    2016-11-25 08:38:55
 ///
 
#include "_THE_INFO_OF_RUN.h"
#include "_MutexLock.h"
namespace T520
{
MutexLock::MutexLock()
{
	pthread_mutex_init(&_mutex,NULL);
}
MutexLock::~MutexLock()
{
	pthread_mutex_destroy(&_mutex);
}
void MutexLock::lock()
{
	pthread_mutex_lock(&_mutex);
}
void MutexLock::unlock()
{
	pthread_mutex_unlock(&_mutex);
}
pthread_mutex_t *MutexLock::getMutexLockPtr()
{
	return &_mutex;
}
}
