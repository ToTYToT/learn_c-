 ///
 /// @file    _Threadpool.h
 /// @author  ToTYToT(hongzimeng@foxmail.com)
 /// @date    2016-11-25 17:48:08
 ///
#ifndef __T_THREADPOOL_H__
#define __T_THREADPOOL_H__
#include "_THE_INFO_OF_RUN.h"
#include "_Buffer.h"
#include "_Task.h"
#include <vector>
#include <memory>
namespace T520
{
class Thread;
class Threadpool
{
	friend class WorkerThread;
public:
	Threadpool(size_t threadNum,size_t bufSize);
	~Threadpool();
	void start();
	void stop();
	void addTask(Task task);
private:
	Task getTask();
	void threadFunc();
private:
	size_t _threadNum;
	size_t _bufSize;
	std::vector<std::shared_ptr<Thread> > _threads;
	Buffer _buffer;
	bool _isExit;
};
}
#endif
