 ///
 /// @file    Derived1.cc
 /// @author  lemon(haohb13@gmail.com)
 /// @date    2016-11-07 10:54:56
 ///
 
#include <iostream>
using std::cout;
using std::endl;

class Base
{
public:
	Base()
	{
		cout << "Base()" << endl;
	}
};


//1.派生类有显式定义构造函数，而基类没有显式定义构造函数，
//则此时创建派生类对象时，会自动调用基类的无参构造函数
class Derived : public Base
{
public:
	Derived()
	{
		cout << "Derived()" << endl;
	}

	Derived(int ix)
	{
		cout << "Derived(int) , ix = " << ix << endl;
	}
};

int main(void)
{
	Derived d;
	return 0;
}
