 ///
 /// @file    multiDerived.cc
 /// @author  lemon(haohb13@gmail.com)
 /// @date    2016-11-07 10:16:20
 ///
 
#include <iostream>
using std::cout;
using std::endl;


class A
{
public:
	void print()
	{	cout << "A::print()" << endl;	}
};

class B 
{
public:
	void show()
	{	cout << "B::show()" << endl;	}
};


//采用public继承，叫接口继承
//采用private继承，叫实现继承
//多重继承时，每一个要继承的基类都要显式提供继承方式，
//如果不提供，默认情况下就是private继承
class C : public A, public B
{
public:
	void display()
	{	cout << "C::display()" << endl;	}
};


int main(void)
{
	C c;
	c.display();
	c.show();
	c.print();

	return 0;
}
