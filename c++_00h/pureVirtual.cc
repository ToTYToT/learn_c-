 ///
 /// @file    pureVirtual.cc
 /// @author  lemon(haohb13@gmail.com)
 /// @date    2016-11-08 15:07:39
 ///
 
#include <iostream>
using std::cout;
using std::endl;


class A
{
public:
	//定义了纯虚函数的类称为抽象类
	virtual void display()=0;
	virtual void display1()=0;
};

class B : public A
{
public:
	//如果派生类继承的基类有多个纯虚函数，
	//则必须全部实现纯虚函数，才能创建派生类对象
	//即使只有一个纯虚函数没有实现，该派生类
	//也会成为抽象类
	void display()
	{
		cout << "B::display()" << endl;
	}

	void display1()
	{
		cout << "B::display1()" << endl;
	}
};

class C : public B
{
public:
	void display()
	{
		cout << "C::display()" << endl;
	}

	void display1()
	{
		cout << "C::display1()" << endl;
	}
};


int main(void)
{
	//A a;//抽象类不能创建对象
	A * pa = NULL;
	pa = new C;
	pa->display();
    pa= new B;
    pa->display();
	return 0;
}
