 ///
 /// @file    Point3.cc
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

	//如果成员函数不会修改数据成员，都将该成员函数声明为const的成员函数
	void print(/*const Point * const this*/) const;
	void print(/* Point * const this */);
private:
	int _ix;
	int _iy;
};



Point::Point(int ix, int iy)
: _ix(ix)
, _iy(iy)
{
	cout << "Point(int,int)" << endl;
}

void Point::print() const
{
//	_ix = 100;//Error
	cout << "(" << _ix
		 << "," << _iy
		 << ")" << endl;
}

#if 1
void Point::print()
{
	cout << "[" << _ix
		 << "," << _iy
		 << "]" << endl;
}
#endif



int main(void)
{
	Point pt1;//非const对象可以使用const成员函数
	pt1.print();

	Point pt2(1, 2);
	pt2.print();

	const Point pt3(3, 4);//const对象只能调用const成员函数
	pt3.print();

	return 0;
}
