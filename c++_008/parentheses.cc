 ///
 /// @file    parentheses.cc
 /// @author  lemon(haohb13@gmail.com)
 /// @date    2016-10-25 10:02:21
 ///
 
#include <iostream>
using std::cout;
using std::endl;

class Demo
{
public:
	//函数调用运算符
	double operator()(double x, double y)
	{
		return x > y ? x : y;
	}

	double operator()(double x, double y, double z)
	{
		return (x + y) * z;
	}
};


int main(void)
{
	Demo demo;
	cout << demo(2.5, 0.2) << endl;// 函数对象
	cout << demo(1.2, 1.5, 7) << endl;

	return 0;
}
