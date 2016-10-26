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

	AnotherPoint ap1(3, 4);
	cout << "ap1 = " << ap1 << endl;

	pt1 = ap1;//自定义类型也可以通过构造函数进行隐式转换
	cout << "pt1 = " << pt1 << endl;

	return 0;
}

