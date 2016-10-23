 ///
 /// @file    Mutex_Condition.cc
 /// @author  ToTYToT(hongzimeng@foxmail.com)
 /// @date    2016-10-23 08:46:57
 ///
#include "log4cpp_mylog.h"

#include <pthread.h>
#include <iostream>
using std::cout;
using std::endl;

class MutexLock
{
public:
    //MutexLock(pthread_mutex_t lock);
    MutexLock();
    ~MutexLock();
    void lock();
    void unlock();
    pthread_mutex_t _lock;
private:
};
//MutexLock::MutexLock(pthread_mutex_t lock)
//:_lock(lock)
MutexLock::MutexLock()
{
	//logWarn("Message_use_define");
    cout << "MutexLock()"<<endl;
	pthread_mutex_init(&_lock,NULL);
}
MutexLock::~MutexLock()
{
    cout << "~MutexLock()"<<endl;
    pthread_mutex_destroy(&_lock);
}
void MutexLock::lock()
{
    cout << "lock()"<<endl;
    pthread_mutex_lock(&_lock);
}
void MutexLock::unlock()
{
    cout << "unlock()"<<endl;
    pthread_mutex_unlock(&_lock);
}
class Condition
{
public:
	Condition(MutexLock & mutex);
	//void wait(MutexLock & mutex);
	void wait();
	void notify();
	void notifyall();
private:
	//...
	MutexLock & _mutex;
	pthread_cond_t _cond;
};
Condition::Condition(MutexLock & mutex)
:_mutex(mutex)
{
	cout<<__func__<<" "<<__LINE__<<endl;
	pthread_cond_init(&_cond,NULL);
}
void Condition::wait()
{
	cout<<__func__<<" "<<__LINE__<<endl;
	pthread_cond_wait(&_cond,&_mutex._lock);
}
void Condition::notify()
{
	cout<<__func__<<" "<<__LINE__<<endl;
	pthread_cond_signal(&_cond);
}
void Condition::notifyall()
{
	cout<<__func__<<" "<<__LINE__<<endl;
	pthread_cond_broadcast(&_cond);
}

int main()
{
    //pthread_mutex_t lock;
    //MutexLock lock_1(lock);
    MutexLock lock_1;
    lock_1.lock();
    lock_1.unlock();
	Condition my_cond(lock_1);
	//my_cond.wait();
	my_cond.notify();
	my_cond.notifyall();
}
