 ///
 /// @file    Point3D.cc
 /// @author  lemon(haohb13@gmail.com)
 /// @date    2016-11-07 09:44:50
 ///
 
#include <iostream>

using std::cout;
using std::endl;



class Point
{
public:
	Point(int ix, int iy)
	: _ix(ix)
	, _iy(iy)
	{
		cout << "Point(int,int)" << endl;
	}

	//如果Point是基类，则其派生类对象都可以作为
	//实参传递过来 ==> 派生类适应基类
	Point & operator=(const Point & rhs)
	{
		cout << "Point & operator=(const Point & rhs)" << endl;
		if(this != &rhs)
		{
			_ix = rhs._ix;
			_iy = rhs._iy;
		}
		return *this;
	}

	int getx() const
	{	return _ix;	}

	int gety() const
	{	return _iy;	}

	friend std::ostream & operator<<(std::ostream & os, const Point & rhs);

private:
	int _ix;
	int _iy;
};

std::ostream & operator<<(std::ostream & os, const Point & rhs)
{
	os << "(" << rhs._ix
	   << "," << rhs._iy
	   << ")";
	return os;
}

class Point3D : public Point
{
public:
	Point3D(int ix, int iy, int iz)
	: Point(ix, iy)
	, _iz(iz)
	{
		cout << "Point3D(int,int,int)" << endl;
	}

	//
	//Point3D & operator=(const Point3D & rhs);

	void display()
	{
		cout << "(" << getx()
		     << "," << gety()
			 << "," << _iz
			 << ")" << endl;
	}
private:
	int _iz;
};


int main(void)
{
	Point pt(1, 2);
	cout << pt << endl;

	Point3D pt3d(3, 4, 5);
	pt3d.display();

	pt = pt3d;//派生类可以直接赋值给基类
	cout << pt << endl;
	
	//pt3d = pt;//右操作数应该是Point3D类型，


	cout << endl;
	Point & ref = pt3d;
	cout << ref << endl;

	Point * p = &pt3d;
	cout << *p << endl;

	cout << "sizeof(Point) = " << sizeof(Point) << endl;
	cout << "sizeof(Point3D) = " << sizeof(Point3D) << endl;

	//Point3D * pp = &pt;

	return 0;
}
