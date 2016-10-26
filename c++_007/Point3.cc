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
//自由函数
	Line(){};
	Line(float dis)
	: _dis(dis)
	{
	
	}
	float distance(const Point & lhs, const Point & rhs);
	void setPoint(Point * pt, int ix, int iy);

	void display() const
	{	cout << "_dis = " << _dis << endl;	}
private:
	float _dis;
};

class Point
{
	//友元函数之友元类, 是单向的,不可传递
	friend class Line;// Line是Point的友元类;但是Point并不是Line的友元类
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

#if 0
	void setDistance(Line * line, float dis)
	{
		line->_dis = dis;//无法直接访问的
	}
#endif

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

void Line::setPoint(Point * pt, int ix, int iy)
{
	pt->_ix = ix;
	pt->_iy = iy;
}

int main(void)
{
	Line line;
	Point pt1(1, 2);
	Point pt2(3, 4);
	pt1.print();
	cout << "到";
	pt2.print();
	//pt2.setDistance(line,4.0);
	cout <<"的距离是" << line.distance(pt1, pt2) << endl << endl;

	line.setPoint(&pt1, 5, 6);
	pt1.print();

	return 0;
}
