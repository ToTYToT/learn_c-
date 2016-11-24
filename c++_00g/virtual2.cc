 ///
 /// @file    virtual1.cc
 /// @author  lemon(haohb13@gmail.com)
 /// @date    2016-11-07 16:07:40
 ///
 
#include <iostream>
using std::cout;
using std::endl;

//空类所占据的存储空间是1
//? 为了区分其实例化的对象是不同的对象，用不同的地址值来标识
class Base
{
public:
	Base(double ix = 0) : _ix(ix) {}
	virtual 
	int func(int x)
	{
		cout << "Base::func(int)" << endl;
		return x;
	}
private:
	double _ix;
};

class Sub : public Base
{
public:
	Sub(double ix, double iy)
	: Base(ix)
	, _dy(iy)
	{}


#if 1
	//1.在没有重定义虚函数时，Sub类的虚表中存放的是
	//Base::func的地址
	//2.一旦要重定义基类的虚函数时，Sub类中虚表的Base::func
	//函数地址会被Sub::func函数地址所覆盖
	//3. 动态多态发生在运行时
	int func(int x)
	{
		cout << "Sub::func(int)" << endl;
		float y = x;
		return y;
	}
#endif

	//派生类定义新增一个虚函数，不是重定义或者覆盖
	//virtual 
	int func()
	{
		cout << "Sub::func()" << endl;
		return 1;
	}
private:
	double _dy;
};

void test(Base & base)
{
	cout << "x = " << base.func(5) << endl;
}


#if 0
int main(void)
{
	cout << "sizeof(Base) = " << sizeof(Base) << endl;

	Base b1;
	Base b2;

	cout << "&b1 = " << &b1 << endl;
	cout << "&b2 = " << &b2 << endl;

	return 0;
}
#endif

int main(void)
{
	cout << "sizeof(Base) = " << sizeof(Base) << endl;
	cout << "sizeof(Sub) = " << sizeof(Sub) << endl;

	Base base(1);
	Sub sub(1, 2);
	test(base);
	test(sub);

	cout << endl;
	Base * p1 = &sub;//虚函数的运行机制：
					 //1. 派生类要覆盖基类的虚函数
					 //2. 基类的指针或者引用指向派生类对象
					 //3. 通过基类的指针或者引用调用虚函数
	p1->func(1);

	sub.func(2);// 并不会体现激活虚函数机制
	
	return 0;
}
