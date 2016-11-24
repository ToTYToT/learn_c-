 ///
 /// @file    virtual1.cc
 /// @author  lemon(haohb13@gmail.com)
 /// @date    2016-11-07 16:07:40
 ///
 
#include <iostream>
using std::cout;
using std::endl;

class Base
{
public:
	virtual int func(int x)
	{
		cout << "Base::func(int)" << endl;
		return x;
	}
};

class Sub : public Base
{
public:
	//virtual float func(int x)
	//对于虚函数而言，如果是要在派生类中重定义基类的虚函数
	//必须与基类的虚函数完全保持一致,即使是返回值类型也不能不一样
	//覆盖
	virtual int func(int x)
	{
		cout << "Sub::func(int)" << endl;
		float y = x;
		return y;
	}

	//派生类定义新增一个虚函数，不是重定义或者覆盖
	virtual int func()
	{
		cout << "Sub::func()" << endl;
		return 1;
	}
};

void test(Base & base)
{
	cout << "x = " << base.func(5) << endl;
}


int main(void)
{
	Base base;
	Sub sub;

	test(base);
	test(sub);

	Base & ref = sub;
	//ref.func();//Error,因为基类中没有func()的定义
	sub.func();

	return 0;
}
