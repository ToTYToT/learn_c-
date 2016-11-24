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


//2.派生类没有显式定义构造函数，而基类有显式定义有参构造函数，
//则此时创建派生类对象时，必须给基类显式定义一个无参构造函数
class Derived : public Base
{
public:
};

int main(void)
{
	Derived d;
	return 0;
}
