 ///
 /// @file    Condition.h
 /// @author  lemon(haohb13@gmail.com)
 /// @date    2016-10-24 10:31:57
 ///
 

#ifndef __WANGDAO_CONDITION_H__
#define __WANGDAO_CONDITION_H__

#include <pthread.h>
#include <iostream>
using std::cout;
using std::endl;


class MutexLock;//前向声明, 减少出现循环引用的几率

class Condition
{
public:
	Condition(MutexLock & mutex);
	~Condition();

	void wait();
	void notify();
	void notifyall();
private:
	pthread_cond_t _cond;
	MutexLock & _mutex;
};

#endif
