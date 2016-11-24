 ///
 /// @file    shared_ptr2.cc
 /// @author  lemon(haohb13@gmail.com)
 /// @date    2016-11-05 11:30:06
 ///
 
#include <iostream>
#include <memory>
using std::cout;
using std::endl;
using std::shared_ptr;



class Point 
: public std::enable_shared_from_this<Point>
{
public:
	Point(int ix, int iy)
	: _ix(ix)
	, _iy(iy)
	{
		cout << "Point(int,int)" << endl;
	}

	~Point()
	{
		cout << "~Point()" << endl;
	}


#if 0
	Point * add(const Point * rhs)
	{
		_ix += rhs->_ix;
		_iy += rhs->_iy;
		return this;
	}
#endif

	shared_ptr<Point> add(const Point * rhs)
	{
		_ix += rhs->_ix;
		_iy += rhs->_iy;
		//return shared_ptr<Point>(this);
		return shared_from_this();//从类内部获取对象的shared_ptr
	}
private:
	int _ix;
	int _iy;
};


int test1(void)
{	//误用方式1
	Point * pt = new Point(1, 2);
	shared_ptr<Point> p1(pt);
	shared_ptr<Point> p2(pt);

	cout << "p1's use_count = " << p1.use_count() << endl;
	cout << "p2's use_count = " << p2.use_count() << endl;

	return 0;
}

int test2()
{
	shared_ptr<Point> p1(new Point(1, 2));
	shared_ptr<Point> p2(new Point(3, 4));
cout<<"here"<<endl;
	//误用方式2
p2.reset(p1.get());
cout<<"here"<<endl;
//	shared_ptr<Point> p3(p2->add(p1.get()));

	return 0;
}

int main(void)
{
	test1();
    cout<<"test1"<<endl;
	test2();

	return 0;
}

