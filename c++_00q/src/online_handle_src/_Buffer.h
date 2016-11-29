 ///
 /// @file    _Buffer.h
 /// @author  ToTYToT(hongzimeng@foxmail.com)
 /// @date    2016-11-24 21:45:22
 ///
#ifndef __T_BUFFER_H__
#define __T_BUFFER_H__
#include "_MutexLock.h"
#include "_Condition.h"
#include "_Task.h"
#include "_THE_INFO_OF_RUN.h"
#include <queue>
using std::queue;
namespace T520
{
typedef Task Data;
class Buffer
{
public:
	Buffer(size_t size);
	void push(Data data);
	Data pop();
	void wakeup();
	bool full() const;
	bool empty() const;
private:
	size_t _queSize;
	queue<Data> _que;
	MutexLock _mutex;
	Condition _notFull;
	Condition _notEmpty;
	bool _flag;
};
}
#endif
