 ///
 /// @file    WorkerThread.cc
 /// @author  lemon(haohb13@gmail.com)
 /// @date    2016-11-16 11:12:37
 ///
 
#include "WorkerThread.h"
#include "Threadpool.h"

#define THE_INFO_OF_RUN (std::cout<<"    FILE:"<<__FILE__<<"    function:"<<__func__<<"    LINE:"<<__LINE__<<endl)
#include <iostream>

namespace wd
{

WorkerThread::WorkerThread(Threadpool & threadpool)
: _threadpool(threadpool)
{
        THE_INFO_OF_RUN;
}

void WorkerThread::run()
{
        THE_INFO_OF_RUN;
	_threadpool.threadFunc();
}


}//  end of namespace wd
