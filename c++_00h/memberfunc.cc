 ///
 /// @file    memberfunc.cc
 /// @author  lemon(haohb13@gmail.com)
 /// @date    2016-11-08 14:34:34
 ///
 
#include <iostream>
using std::cout;
using std::endl;

class Base
{
public:
	virtual
	void display()
	{	cout << "Base::display()" << endl;	}

	void func1()
	{	
		display();//与this指针有关,表现多态性
	}

	void func2()
	{
		Base::display();//直接到方法区找
	}
};


class Sub : public Base
{
public:
	void display()
	{
		cout << "Sub::display()" << endl;
	}

	void subfunc1()
	{
		display();
	}

	void func1()
	{
		display();
	}

	void func2()
	{
		Base::display();
	}
};


int main(void)
{
	Base base;
	Sub sub;
	base.func1();//
	sub.subfunc1();
	cout << endl;

	Base * pbase = &base;
	pbase->func1();
	pbase->func2();
	cout << endl;

	pbase = &sub;
	pbase->func1();
	pbase->func2();

	return 0;
}

