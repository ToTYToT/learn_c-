 ///
 /// @file    inline.cc
 /// @author  lemon(haohb13@gmail.com)
 /// @date    2016-10-18 15:30:25
 ///
 
#include <iostream>
using std::cout;
using std::endl;

//#define max(x,y) ((x) > (y) ? (x) : (y))

inline int max(int x, int y)
{
	return (x > y ? x : y);
}
