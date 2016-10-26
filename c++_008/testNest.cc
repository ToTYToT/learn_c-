 ///
 /// @file    testNest.cc
 /// @author  lemon(haohb13@gmail.com)
 /// @date    2016-10-25 11:55:28
 ///
 
#include "nest.h"
#include <iostream>
using std::cout;
using std::endl;


int main(void)
{
	Line line(1, 2, 3, 4);
	line.printLine();

	cout << sizeof(Line) << endl;

	return 0;
}
