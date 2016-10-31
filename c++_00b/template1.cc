 ///
 /// @file    template1.cc
 /// @author  lemon(haohb13@gmail.com)
 /// @date    2016-10-29 09:54:10
 ///
 
#include <iostream>
#include <string> 
using std::cout;
using std::endl;
using std::string;

//函数模板
//只是一个声明
template <typename T>
T add(const T & a, const T & b);

#if 0

//这些函数都是由编译器通过函数模板生成的,
//可以模板看成是一个代码生成器
//模板函数
int add(const int & a, const int & b)
{
	return a + b;
}

double add(const double & a, const double & b)
{
	return a + b;
}

string add(const string & a, const string & b)
{
	return a + b;
}
#endif


int main(void)
{
	cout << add(10, 20) << endl;//隐式实例化
	cout << add(1.0, 2.0) << endl;
	string s1("hello"), s2("world");
	cout << add(s1, s2) << endl; 
	return 0;
}

template <typename T>
T add(const T & a, const T & b)
{
	return a + b;
}
