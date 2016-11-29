 ///
 /// @file    _Threadpool.cc
 /// @author  ToTYToT(hongzimeng@foxmail.com)
 /// @date    2016-11-25 17:53:01
 ///
 
#include "_THE_INFO_OF_RUN.h"
#include "_Threadpool.h"
#include "_Thread.h"
#include <unistd.h>
#include <functional>
namespace T520
{
Threadpool::Threadpool(size_t threadNum, size_t bufSize)
:_threadNum(threadNum)
,_bufSize(bufSize)
,_buffer(_bufSize)
,_isExit(false)
{
	THE_INFO_OF_RUN;
	_threads.reserve(_threadNum);
}
Threadpool::~Threadpool()
{
	THE_INFO_OF_RUN;
	if(!_isExit)
	{
		stop();
	}
}
void Threadpool::start()
{
	THE_INFO_OF_RUN;
	for(size_t idx=0; idx !=_threadNum; ++idx)
	{
		std::shared_ptr<Thread> sp(new Thread(std::bind(&Threadpool::threadFunc,this)));
		_threads.push_back(sp);
		sp->start();
	}
}
void Threadpool::stop()
{
	THE_INFO_OF_RUN;
	if(!_isExit)
	{
		while(!_buffer.empty())
		{
			::sleep(1);
		}
		_isExit=true;
		_buffer.wakeup();
		for(auto & elem: _threads)
		{
			elem->join();
		}
	}
}
void Threadpool::addTask(Task task)
{
	THE_INFO_OF_RUN;
	_buffer.push(task);
}
Task Threadpool::getTask()
{
	THE_INFO_OF_RUN;
	return _buffer.pop();
}
void Threadpool::threadFunc()
{
	THE_INFO_OF_RUN;
	while(!_isExit)
	{
		Task task=getTask();
		if(task)
			task();
	}
}
}
