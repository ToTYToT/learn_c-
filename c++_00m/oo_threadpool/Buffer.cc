 ///
 /// @file    Buffer.cc
 /// @author  lemon(haohb13@gmail.com)
 /// @date    2016-11-15 14:55:54
 ///
 
#include "Buffer.h"
#include <iostream>
#define THE_INFO_OF_RUN (std::cout<<"    FILE:"<<__FILE__<<"    function:"<<__func__<<"    LINE:"<<__LINE__<<endl)
using std::cout;
using std::endl;


namespace wd
{

Buffer::Buffer(size_t size)
: _queSize(size)
, _mutex()
, _notFull(_mutex)
, _notEmpty(_mutex)
, _flag(true)
{}

bool Buffer::full() const
{
        THE_INFO_OF_RUN;
	return _queSize == _que.size();
}

bool Buffer::empty() const
{
        THE_INFO_OF_RUN;
	return 0 == _que.size();
}


void Buffer::wakeup()
{
        THE_INFO_OF_RUN;
	_flag = false;
	_notEmpty.notifyAll();
}

//push方法运行在生产者线程
void Buffer::push(Data data)
{
        THE_INFO_OF_RUN;
	MutexLockGuard mlg(_mutex);
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
        THE_INFO_OF_RUN;
	MutexLockGuard mlg(_mutex);
	while(_flag && empty())
	{
		_notEmpty.wait();
	}
//	if(empty())return NULL;
	if(_flag)
	{
		Data queItem = _que.front();
		_que.pop();
		_notFull.notify();
		return queItem;
	}else{
		return NULL;
	}
}


}// end of namespace wd
