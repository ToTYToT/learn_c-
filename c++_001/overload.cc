 ///
 /// @file    overload.c
 /// @author  lemon(haohb13@gmail.com)
 /// @date    2016-10-17 16:16:39
 ///
 

//C++支持函数重载,其实现原理：名字改编(name mangling)
//具体操作： 当函数名称相同时，根据函数参数的类型，个数，顺序
//来进行名字改编

#include <stdio.h>
#include <iostream>
using std::cout;
using std::endl;


#ifdef __cplusplus
extern "C"  //以C的方式进行调用
{
#endif
int add(int a, int b)
{
	return a + b;
}

#ifdef __cplusplus
}// end of extern "C"
#endif


int add(int a, int b, int c)
{
	return a + b + c;
}


int main(void)
{
	int x = 1, y = 2, z = 3;
	cout << add(x, y) << endl;
	cout << add(x, y, z) << endl;
	return 0;
}
