 ///
 /// @file    Buffer.cc
 /// @author  lemon(haohb13@gmail.com)
 /// @date    2016-11-15 14:55:54
 ///
 
#include "Buffer.h"
#include <iostream>
using std::cout;
using std::endl;


namespace wd
{

Buffer::Buffer(size_t size)
: _queSize(size)
, _mutex()
, _notFull(_mutex)
, _notEmpty(_mutex)
{}

bool Buffer::full() const
{
	return _queSize == _que.size();
}

bool Buffer::empty() const
{
	return 0 == _que.size();
}

//push方法运行在生产者线程
void Buffer::push(Data data)
{
	MutexLockGuard mlg(_mutex);//异常退出解锁
	while(full())  //使用if不能处理条件变量被异常唤醒的情况
	{
		_notFull.wait();
	}
	_que.push(data);
	_notEmpty.notify();
}

//pop方法运行在消费者线程
Data Buffer::pop()
{
	MutexLockGuard mlg(_mutex);
	while(empty())
	{
		_notEmpty.wait();
	}
	Data queItem = _que.front();
	_que.pop();
	_notFull.notify();
	return queItem;
}


}// end of namespace wd
