 ///
 /// @file    overload.c
 /// @author  lemon(haohb13@gmail.com)
 /// @date    2016-10-17 16:16:39
 ///
 

#include <stdio.h>

//在C语言里，没有实现函数重载的功能
int add(int a, int b)
{
	return a + b;
}


int add(int a, int b, int c)
{
	return a + b + c;
}


int main(void)
{
	int x = 1, y = 2, z = 3;
	add(x, y);
	add(x, y, z);
	return 0;
}
