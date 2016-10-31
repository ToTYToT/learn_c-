 ///
 /// @file    template2.cc
 /// @author  lemon(haohb13@gmail.com)
 /// @date    2016-10-29 10:06:25
 ///
 
#include <iostream>
using std::cout;
using std::endl;

//模板参数列表的参数有2种形式
//1. 使用class或typename进行修饰的类类型
//2. 非类型参数 int, 代表一个常量
template <typename T, int NUM>
T func(T a)
{
	return a * NUM;
}

int main(void)
{
	cout << func<int, 4>(3) << endl;//实例化的方式--> 显式实例化

	return 0;
}
