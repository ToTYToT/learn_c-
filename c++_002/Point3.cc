 ///
 /// @file    Point.cc
 /// @author  lemon(haohb13@gmail.com)
 /// @date    2016-10-18 11:38:00
 ///
 
#include <unistd.h>
#include <iostream>
using std::cout;
using std::endl;


class Point
{
public:
	//构造函数可以进行重载的
	Point(int ix = 0, int iy = 0);//有参构造函数

	~Point();

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
: _ix(ix)
, _iy(iy)  //初始化列表
{
	cout << "Point(int,int)" << endl;
	//_ix = ix;//赋值
	//_iy = iy;
}


Point::~Point()
{
	cout << "~Point()" << endl;
}

void Point::print()
{
	cout << "(" << _ix
		 << "," << _iy
		 << ")" << endl;
}

int main(void)
{
	{
	Point pt1;
	pt1.print();
	}

	sleep(1);
	Point pt2(1, 2);
	pt2.print();

	Point * p = new Point(5, 6);
	p->print();

	delete p;

	return 0;
}
