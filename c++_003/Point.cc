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
	Point(int ix = 0, int iy = 0);
//	Point(int ix , int iy );

	void print();
private:
	const int _ix;
	const int _iy;
};



Point::Point(int ix, int iy)
: _ix(ix)
, _iy(iy)
{
	cout << "Point(int,int)" << endl;
	//_ix = ix;//赋值
	//_iy = iy;
}

void Point::print()
{
	cout << "(" << _ix
		 << "," << _iy
		 << ")" << endl;
}

int main(void)
{
	Point pt1;
	pt1.print();

	Point pt2(1, 2);
	pt2.print();

	return 0;
}
