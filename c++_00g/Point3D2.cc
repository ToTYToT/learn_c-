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

	int getx() const
	{	return _ix;	}

protected://该成员在派生类中可以直接访问
	int gety() const
	{	return _iy;	}


private:
	int _ix;
	int _iy;
};


class Point3D : public Point
{
public:
	Point3D(int ix, int iy, int iz)
	: Point(ix, iy)
	, _iz(iz)
	{
		cout << "Point3D(int,int,int)" << endl;
	}

	void display()
	{
		//cout << _ix;//对于基类的私有成员，在子类内部不能直接访问
		cout << "(" << getx()  //基类的公有成员在派生类内部可以直接访问
		     << "," << gety()  //
			 << "," << _iz
			 << ")" << endl;
	}
private:
	int _iz;
};


int main(void)
{
	Point3D p(3, 4, 5);
	p.display();
	

	cout << "x = " << p.getx() << endl;
	return 0;
}
