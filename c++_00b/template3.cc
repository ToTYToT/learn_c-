 ///
 /// @file    template3.cc
 /// @author  lemon(haohb13@gmail.com)
 /// @date    2016-10-29 10:28:01
 ///
 
#include <iostream>
using std::cout;
using std::endl;


//普通函数能够与函数模板构成重载
//在调用时,如果传递的实参与普通函数的参数保持一致,
//会优先调用普通函数
int max(int x, int y)
{
	cout << "max(int,int)" << endl;
	return x > y ? x : y;
}

template <typename T>
T max(T x, T y)
{
	cout << "template max(x,y) " << endl;
	return x > y ? x : y;
}

//函数模板与函数模板之间也能进行重载
template <typename T>
T max(T x, T y, T z)
{
	cout << "template max(x,y,z)" << endl;
	return x > y ? (x > z ? x : z) : (y > z ? y : z);
}


int main(void)
{
	int a = 1, b = 9;
	char c1 = 'a', c2 = 'b';
	double d1 = 1.0, d2 = 9.0, d3 = 3.3;
	int ret1 = max(a, b);
	char ret2 = max(c1, c2);
	double ret3 = max(d1, d2, d3);

	cout << "ret1 = " << ret1 << endl;
	cout << "ret2 = " << ret2 << endl;
	cout << "ret3 = " << ret3 << endl;

	return 0;
}
