 ///
 /// @file    Point.cc
 /// @author  lemon(haohb13@gmail.com)
 /// @date    2016-10-19 16:38:00
 ///
 
#include <iostream>
using std::cout;
using std::endl;


class Point
{
public:
	Point(int ix, int iy, double & z);

	Point(const Point & rhs)
	: _ix(rhs._ix)
	, _iy(rhs._iy)
	, _ref1(rhs._ref1)
	, _ref2(rhs._ref2)
	{
		cout << "Point(const Point &rhs)" << endl;
	}

	void setx(int ix)
	{	_ix = ix;	}

	void print();
private:
	int _ix;
	int _iy;
	int & _ref1;
	double & _ref2;
};


Point::Point(int ix, int iy, double & z)
: _ix(ix)
, _iy(iy)
, _ref1(_ix)
, _ref2(z)
{
	cout << "Point(int,int)" << endl;
}

void Point::print()
{
	cout << "(" << _ix
		 << "," << _iy
		 << "," << _ref1
		 << "," << _ref2
		 << ")" << endl;
}

int main(void)
{
	double dz = 5.0;
	Point pt1(3, 4, dz);
	pt1.print();

	Point pt2(pt1);
	pt2.print();
	cout << endl;

	cout << "改变pt1中的 _ix之后:" << endl;
	pt1.setx(7);
	pt1.print();
	pt2.print();

	cout << "改变dz的值之后:" << endl;
	dz = 6.0;
	pt1.print();
	pt2.print();

	return 0;
}
