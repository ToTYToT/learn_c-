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

	//this代表对象本身，不能作修改
	//赋值运算符函数的返回值使用 引用，而不是对象
	Point & operator=(/*Point * const this, */const Point & rhs)
	{
		if(this != &rhs) //考虑一个自复制的问题
		{
			this->_ix = rhs._ix;
			this->_iy = rhs._iy;
		}
		return *this;
	}

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
: _ix(rhs._ix)
, _iy(rhs._iy)
{
	cout << "Point(const Point & rhs)" << endl;
}

Point::~Point()
{
	cout << "~Point()" << endl;
}

void Point::print()
{
	cout << "(" << this->_ix
		 << "," << this->_iy
		 << ")" << endl;
}

int main(void)
{
	int a = 3;
	int b = 4;
	b = a;

	Point pt1(1,2);
	pt1.print();
	Point pt2 = pt1;// 复制构造函数
	pt2.print();
	//Point pt2(pt1);
	Point pt3(4, 5);

	pt3 = pt1;//赋值运算符函数
	pt3.print();

	//pt2 = pt2;


}
