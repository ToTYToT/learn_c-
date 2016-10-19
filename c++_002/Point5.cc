 ///
 /// @file    Point.cc
 /// @author  lemon(haohb13@gmail.com)
 /// @date    2016-10-18 11:38:00
 ///
 
#include <iostream>
using std::cout;
using std::endl;


class Point
{
public:
	//implicit
	explicit // 可以禁止隐式转换
	Point(int ix = 0, int iy = 0);

	void print();
private:
	int _ix;
	int _iy;
};


#if 0
Point::Point()
{
	cout << "Point()" << endl;
	_ix = 0;
	_iy = 0;
}
#endif

Point::Point(int ix, int iy)
{
	cout << "Point(int,int)" << endl;
	_ix = ix;
	_iy = iy;
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

	Point pt3 = 5;//隐式转换,中间会生成一个临时对象
	pt3.print();

	return 0;
}
