 ///
 /// @file    Point.cc
 /// @author  lemon(haohb13@gmail.com)
 /// @date    2016-10-24 16:00:11
 ///
 
#include <math.h>
#include <iostream>
using std::cout;
using std::endl;

class Point;

class Line
{
public:
//Line成员函数
	float distance(const Point & lhs, const Point & rhs);
};

class Point
{
	//友元函数之成员函数
	friend float Line::distance(const Point & lhs, const Point & rhs);
public:
	Point(int ix, int iy)
	: _ix(ix)
	, _iy(iy)
	{
	}

	void print() const
	{
		cout << "(" << _ix
			 << "," << _iy
			 << ")" << endl;
	}

	int getx() const
	{	return _ix;	}
	int gety() const
	{	return _iy;	}
private:
	int _ix;
	int _iy;
};


float Line::distance(const Point & lhs, const Point & rhs)
{
	return sqrt((lhs._ix- rhs._ix) * (lhs._ix - rhs._ix)
		      + (lhs._iy - rhs._iy) * (lhs._iy - rhs._iy));
}

int main(void)
{
	Line line;
	Point pt1(1, 2);
	Point pt2(3, 4);
	pt1.print();
	cout << "到";
	pt2.print();
	cout <<"的距离是" << line.distance(pt1, pt2) << endl;

	return 0;
}
