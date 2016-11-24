 ///
 /// @file    Derived2.cc
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

	//有显式定义一个有参构造函数时，
	//系统就不会再提供无参构造函数
	Base(int ix)
	: _ix(ix)
	{
		cout << "Base(int) " << endl;
	}
private:
	int _ix;
};


//3.派生类有显式定义构造函数，而基类有显式定义有参构造函数，
//则此时创建派生类对象时，如果希望调用基类的有参构造函数，
//必须在派生类构造函数初始化列表中显式调用基类的有参构造函数
class Derived : public Base
{
public:
	Derived()
	: Base() //对于无参的构造函数也可以放在初始化列表之中
	{	cout << "Derived()" << endl;	}

	Derived(int ix) 
	: Base(ix)
	{
		cout << "Derived(int)" << endl;
	}
};

int main(void)
{
	Derived d0;
	Derived d(3);
	return 0;
}
