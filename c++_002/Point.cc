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
	//构造函数可以进行重载的
	Point();//默认构造函数
//	Point(int ix = 0, int iy = 0);//有参构造函数

	void print();
private:
	int _ix;
	int _iy;
};


#if 1
Point::Point()
{
	cout << "Point()" << endl;
	_ix = 0;
	_iy = 0;
}
#endif

#if 0
Point::Point(int ix, int iy)
{
	cout << "Point(int,int)" << endl;
	_ix = ix;
	_iy = iy;
}
#endif
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

//	Point pt2(1, 2);
//	pt2.print();

	return 0;
}
