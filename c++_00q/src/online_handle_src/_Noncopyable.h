 ///
 /// @file    _Noncopyable.h
 /// @author  ToTYToT(hongzimeng@foxmail.com)
 /// @date    2016-11-25 08:48:49
 ///
#ifndef __T_NONCOPYABLE_H__
#define __T_NONCOPYABLE_H__
#include "_THE_INFO_OF_RUN.h"
namespace T520
{
class Noncopyable
{
protected:
	Noncopyable(){}
	~Noncopyable(){}
private:
	Noncopyable(const Noncopyable&);
	Noncopyable&operator=(const Noncopyable&);
};
}
#endif
