 ///
 /// @file    Task.h
 /// @author  lemon(haohb13@gmail.com)
 /// @date    2016-11-16 10:58:24
 ///
 
#ifndef __WANGDAO_TASK_H__
#define __WANGDAO_TASK_H__

#include <functional>
using std::function;
namespace wd
{
class Task 
{
public:
	typedef function<void()> ThreadCallback;
	Task(ThreadCallback cb)
	:_cb(cb)
	{

	}
	void cbi(){
		_cb();
	}
private:
	ThreadCallback _cb;
	//virtual void execute()=0;
};

}// end of namespace wd


#endif
