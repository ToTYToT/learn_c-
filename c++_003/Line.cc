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
}

void Point::print()
{
	cout << "(" << _ix
		 << "," << _iy
		 << ")";
}


class Line
{
public:
	Line(int x1, int y1, int x2, int y2)
	: _p1(x1, y1) //初始化对象，会调用Point的含有2个参数的构造函数
	, _p2(x2, y2)
	{
	}

	void display()
	{
		_p1.print();
		cout << "-->";
		_p2.print();
		cout << endl;
	}

private:
	Point _p1;
	Point _p2;
};

int main(void)
{
	Line line(1, 2, 3, 4);
	line.display();

	return 0;
}
