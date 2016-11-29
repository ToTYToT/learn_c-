 ///
 /// @file    _Buffer.cc
 /// @author  ToTYToT(hongzimeng@foxmail.com)
 /// @date    2016-11-24 21:39:24
 ///
 
#include "_Buffer.h"
#include "_THE_INFO_OF_RUN.h"
namespace T520
{
Buffer::Buffer(size_t size)
:_queSize(size)
,_mutex()
,_notFull(_mutex)
,_notEmpty(_mutex)
,_flag(true)
{
	THE_INFO_OF_RUN;
}
bool Buffer::full() const
{
	THE_INFO_OF_RUN;
	return _queSize==_que.size();
}
bool Buffer::empty() const
{
	THE_INFO_OF_RUN;
	return 0==_que.size();
}
void Buffer::wakeup()
{
	THE_INFO_OF_RUN;
	_flag=false;
	_notEmpty.notifyAll();
}
void Buffer::push(Data data)
{
	THE_INFO_OF_RUN;
	MutexLockGuard mlg(_mutex);
	while(full())
	{
		_notFull.wait();
	}
	_que.push(data);
	_notEmpty.notify();
}
Data Buffer::pop()
{
	THE_INFO_OF_RUN;
	MutexLockGuard mlg(_mutex);
	while(_flag && empty())
	{
		_notEmpty.wait();
	}
	if(_flag)
	{
		Data queItem =_que.front();
		_que.pop();
		_notFull.notify();
		return queItem;
	}
	else
	{
		return NULL;
	}
}
}
