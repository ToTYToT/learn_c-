 ///
 /// @file    WorkerThread.cc
 /// @author  lemon(haohb13@gmail.com)
 /// @date    2016-11-16 11:12:37
 ///
 
#include "WorkerThread.h"
#include "Threadpool.h"

#include <iostream>

namespace wd
{

WorkerThread::WorkerThread(Threadpool & threadpool)
: _threadpool(threadpool)
{
}

void WorkerThread::run()
{
	_threadpool.threadFunc();
}


}//  end of namespace wd
