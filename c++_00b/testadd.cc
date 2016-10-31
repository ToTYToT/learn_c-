 ///
 /// @file    testadd.cc
 /// @author  lemon(haohb13@gmail.com)
 /// @date    2016-10-29 10:16:11
 ///
 
//#include "add.h"
#include "add"
#include <iostream>  //没有.h的原因是,其内容是由模板编写的,而模板不能分成头文件和实现文件的,要一起使用
using std::cout;
using std::endl;

int main(void)
{
	cout << add(1.0, 2.0) << endl;
	cout << add(10, 20) << endl;

	return 0;
}
