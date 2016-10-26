 ///
 /// @file    nest.h
 /// @author  lemon(haohb13@gmail.com)
 /// @date    2016-10-25 11:50:13
 ///
#ifndef __NEST_LINE_H__
#define __NEST_LINE_H__
#include <iostream>
using std::cout;
using std::endl;

//设计模式: Pimpl
//1. 实现信息隐藏
//2. 多公司协作开发之中,能够平滑地进行库的升级
//3. 保证二进制兼容性

class Line
{
	class LineImpl;
public:
	Line(int x1, int y1, int x2, int y2);
	~Line();

	void printLine();

private:
	LineImpl * _pImpl;
};


#endif
