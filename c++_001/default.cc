 ///
 /// @file    default.cc
 /// @author  lemon(haohb13@gmail.com)
 /// @date    2016-10-17 16:34:27
 ///
 
#include <iostream>
using std::cout;
using std::endl;


int add(int x, int y = 1) //函数的默认参数(缺省参数)
{
	return x + y;
}

//缺省参数的赋值必须按照从右到左的顺序进行
//在使用缺省参数时要特别注意：不要产生二义性
int add(int x, int y, int z)
{
	return x + y + z;
}


int main(void)
{
	int a = 10, b = 20;
	cout << add(a) << endl;
	cout << add(a, b) << endl;

	return 0;
}
