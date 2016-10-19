 ///
 /// @file    Point4.cc
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
	Point(int ix = 0, int iy = 0);

	//复制构造函数的参数只能是const 引用，不能是对象，
	//如果参数是对象，在发生复制构造时，会导致无穷递归，
	//直到栈溢出
	Point(const Point & rhs);
	//Point(const Point  rhs);

	~Point();

	void print();
private:
	int _ix;
	int _iy;
};

Point::Point(int ix, int iy)
: _ix(ix)
, _iy(iy)  //初始化列表
{
	cout << "Point(int,int)" << endl;
	//_ix = ix;//赋值
	//_iy = iy;
}

Point::Point(const Point & rhs)
//Point::Point(const Point rhs)
: _ix(rhs._ix)
, _iy(rhs._iy)
{
	cout << "Point(const Point  rhs)" << endl;
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

//形参与实参都是对象，并且实参与形参进行结合时，
//会调用复制构造函数
void func1(Point pt)
{// Point pt = pt1
	Point pt1 = pt;
	pt.print();
}

//编译器默认情况下是有优化操作的，
//加上编译选项 -fno-elide-constructors后，
//再执行就会看到复制构造函数被调用的过程
Point func2()
{
	Point pt(3, 4);
	pt.print();
	return pt;
}

int test(void)
{
	Point pt1(1, 2);
	pt1.print();

//	Point pt2 = pt1;//调用复制构造函数
	Point pt2 = pt1;//调用复制构造函数
//	Point pt2(pt1);
	Point pt3(pt1);
	pt2.print();

	return 0;
}

int test1(void)
{
	Point pt1(1, 2);
	func1(pt1);
	return 0;
}

int main(void)
{
	//Point p = func2();
	Point p = func2();
	func2();
	return 0;
}
