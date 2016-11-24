 ///
 /// @file    WorkerThread.h
 /// @author  lemon(haohb13@gmail.com)
 /// @date    2016-11-16 11:10:01
 ///
 
#ifndef __WANGDAO_WORKERTHREAD_H__
#define __WANGDAO_WORKERTHREAD_H__

#include "Thread.h"

#include <iostream>
using std::cout;
using std::endl;

namespace wd
{
class Threadpool;
class WorkerThread : public Thread
{
public:
	WorkerThread(Threadpool & threadpool);

private:
	void run();
private:
	Threadpool & _threadpool;
};

}// end of namespace wd


#endif
