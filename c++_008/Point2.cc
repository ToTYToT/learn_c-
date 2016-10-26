 ///
 /// @file    Point.cc
 /// @author  lemon(haohb13@gmail.com)
 /// @date    2016-10-25 11:18:56
 ///
 
#include <iostream>
using std::cout;
using std::endl;
using std::ostream;

//class Point;

class AnotherPoint
{
	friend class Point;
	friend ostream & operator<<(ostream & os, const AnotherPoint & rhs);
public:
	AnotherPoint(double dx, double dy)
	: _dx(dx)
	, _dy(dy)
	{}



private:
	double _dx;
	double _dy;
};

ostream & operator<<(ostream & os, const AnotherPoint & rhs)
{
	os << "(" << rhs._dx
	   << "," << rhs._dy
	   << ")";
	return os;
}
class Point
{
	friend ostream & operator<<(ostream & os, const Point & rhs);
public:
	Point(int ix, int iy)
	: _ix(ix)
	, _iy(iy)
	{}

	Point(const AnotherPoint & rhs)
	: _ix(rhs._dx)
	, _iy(rhs._dy)
	{
		cout << "Point(const AnotherPoint & rhs)" << endl;
	}

	//类型转换函数
	//1. 必须是成员函数
	//2. 没有返回值类型,但是必须用return以传值勤方式返回一个
	//   目标类型的变量(对象)
	//3. 没有参数
	//4. 一般不会使用
	operator int()
	{
		cout << "operator int()" << endl;
		return _ix;
	}

	operator double()
	{
		cout << "operator double()" << endl;
		return _ix * _iy;
	}

	operator AnotherPoint()
	{
		cout << "operator AnotherPoint()" << endl;
		return AnotherPoint(_ix, _iy);
	}

private:
	int _ix;
	int _iy;
};

ostream & operator<<(ostream & os, const Point & rhs)
{
	os << "(" << rhs._ix
	   << "," << rhs._iy
	   << ")";
	return os;
}


int main(void)
{
	Point pt1(1, 2);
	cout << "pt1 = " << pt1 << endl;
	int a = pt1;
	cout << "a = " << a << endl;

	double b = pt1;
	cout << "b = " << b << endl;

	AnotherPoint ap1(3, 4);
	cout << "ap1 = " << ap1 << endl;
	
	ap1 = pt1;
	cout << "ap1 = " << ap1 << endl;
	

	return 0;
}

