 ///
 /// @file    protected.cc
 /// @author  lemon(haohb13@gmail.com)
 /// @date    2016-11-08 16:00:11
 ///
 
#include <iostream>
using std::cout;
using std::endl;


class Base
{
public:
	void display()
	{
		cout << "Base::_ix = " << _ix << endl;
	}
protected:
	Base(int ix = 0) : _ix(ix)
	{}
private:
	int _ix;
};


class Child : public Base
{
public:
	Base b;//对象成员跟Child无关的,它自己本身是独立的，
			//就是在类之外调用构造函数，无法构建的
#if 0
	Child(int ix) : Base(ix)
	, b()
	{}
    #endif
};

int main(void)
{
	Base base;//Error，不能直接创建对象
	Child child();

	//child.display();

	return 0;
}
