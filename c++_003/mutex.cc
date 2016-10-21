 ///
 /// @file    mutex.cc
 /// @author  ToTYToT(hongzimeng@foxmail.com)
 /// @date    2016-10-19 22:03:22
 ///

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
private:
    pthread_mutex_t _lock;
};
//MutexLock::MutexLock(pthread_mutex_t lock)
//:_lock(lock)
MutexLock::MutexLock()
{
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
int main()
{
    //pthread_mutex_t lock;
    //MutexLock lock_1(lock);
    MutexLock lock_1;
    lock_1.lock();
    lock_1.unlock();
}
