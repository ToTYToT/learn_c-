 ///
 /// @file    Point.cc
 /// @author  lemon(haohb13@gmail.com)
 /// @date    2016-10-25 11:18:56
 ///
 
#include <iostream>
using std::cout;
using std::endl;
using std::ostream;

class Point
{
public:
	Point(int ix, int iy)
	: _ix(ix)
	, _iy(iy)
	{}

	//类型转换函数
	operator int()
	{
		cout << "operator int()" << endl;
		return _ix;
	}
private:
	int _ix;
	int _iy;
};

int main(void)
{
	Point pt1(1, 2);
	//Point并没有重载输出流运算符，
	// 但是Point有一个类型转换函数，能够直接转成 int
	// 此时发生了一个隐式转换
	cout << "pt1 = " << pt1 << endl;

	return 0;
}

