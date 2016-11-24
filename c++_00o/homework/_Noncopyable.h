 ///
 /// @file    _Noncopyable.h
 /// @author  ToTYToT(hongzimeng@foxmail.com)
 /// @date    2016-11-23 21:23:51
 ///
 
#ifndef NONCOPYABLE_H
#define NONCOPYABLE_H
#include <iostream>
#define THE_INFO_OF_RUN (std::cout<<"                "<<__func__<<"    "<<__FILE__<<"-->"<<__LINE__<<std::endl)
using std::cout;
using std::endl;
class Noncopyable
{
	public:
		Noncopyable(){}
		~Noncopyable(){}
	private:
		Noncopyable(const Noncopyable&);
		void operator=(const Noncopyable &);
};
#endif
