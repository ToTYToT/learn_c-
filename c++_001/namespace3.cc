 ///
 /// @file    namespace3.cc
 /// @author  lemon(haohb13@gmail.com)
 /// @date    2016-10-17 11:50:42
 ///
#include <stdio.h> 
#include <stdlib.h>
//#include <cstdio>
//#include <cstdlib>
#include <iostream>
using std::cout;
using std::endl;


//之前C的标准头文件出现的实体都是在匿名的名称空间的
int num = 10;


namespace A
{
int num = 100;

}

namespace B
{
int num = 1000;


void display()
{
	int num = 5;
	cout << "display::num = " << num << endl;//发生了屏蔽
	cout << "B::num = " << B::num << endl;
	cout << "A::num = " << A::num << endl;
	cout << "全局名称空间中的num = " << ::num << endl;//匿名的名称空间
}

}

int main(void)
{
	B::display();

	return 0;
}
