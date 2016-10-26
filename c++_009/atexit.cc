 ///
 /// @file    atexit.cc
 /// @author  lemon(haohb13@gmail.com)
 /// @date    2016-10-26 11:35:54
 ///
 
#include <stdlib.h>
#include <iostream>
using std::cout;
using std::endl;


void func1(void)
{
	cout << "func1()" << endl;
}


int main(void)
{
	cout << "main()" << endl;

	atexit(func1);//当程序结束时,会自动调用已注册的函数
	atexit(func1);
	atexit(func1);

	cout << "~main()" << endl;

	return 0;
}
