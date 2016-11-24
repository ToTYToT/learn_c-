 ///
 /// @file    Threadpool.cc
 /// @author  lemon(haohb13@gmail.com)
 /// @date    2016-11-16 11:06:18
 ///

#include "Threadpool.h"
#include "WorkerThread.h"
#include "Task.h"
 
#include <unistd.h>
#include <iostream>

#define THE_INFO_OF_RUN (std::cout<<"    FILE:"<<__FILE__<<"    function:"<<__func__<<"    LINE:"<<__LINE__<<endl)

using std::cout;
using std::endl;


namespace wd
{

Threadpool::Threadpool(size_t threadNum, size_t bufSize)
: _threadNum(threadNum)
, _bufSize(bufSize)
, _buffer(_bufSize)
, _isExit(false)
{
        THE_INFO_OF_RUN;
	_threads.reserve(_threadNum);
}


Threadpool::~Threadpool()
{
        THE_INFO_OF_RUN;
	if(!_isExit){
		//stop();
	}
}

void Threadpool::start()
{
        THE_INFO_OF_RUN;
	for(size_t idx = 0; idx != _threadNum; ++idx)
	{
		shared_ptr<Thread> sp(new WorkerThread(*this));
		_threads.push_back(sp);
		sp->start();
	}
}


void Threadpool::stop()
{
        THE_INFO_OF_RUN;
	if(!_isExit){
		//先判断任务队列是否还有任务
		while(!_buffer.empty())
		{
			::sleep(1);
		}
		_isExit = true;//放在子线程回收之前
//		_buffer.notempty();
		for(auto & elem : _threads){
        cout<<__LINE__<<endl;
			elem->join();
		}
        cout<<__LINE__<<endl;
	}
}

void Threadpool::addTask(Task * task)
{
        THE_INFO_OF_RUN;
	_buffer.push(task);
}

Task * Threadpool::getTask()
{
        THE_INFO_OF_RUN;
	return _buffer.pop();
}

void Threadpool::threadFunc()
{
        THE_INFO_OF_RUN;
	while(!_isExit)
	//if(!_isExit)
	{
		//while(_buffer.empty())
		if(_buffer.empty())
		{
			continue;
		}
		cout << "threadId: " << pthread_self() << endl;
		Task * task = getTask();
        THE_INFO_OF_RUN;
		if(task)
			task->execute();
	}
}


}// end of namespace wd
