 ///
 /// @file    oversee.cc
 /// @author  lemon(haohb13@gmail.com)
 /// @date    2016-11-08 11:47:10
 ///
 
#include <iostream>
using std::cout;
using std::endl;


class Base
{
public:
	virtual
	int func(int x)
	{	
		cout << "Base::func(int)" << endl;
		return x;
	}
};


class Sub : public Base
{
public:
    #if 0
    int func(int x)
    {
        cout << "Sub::func(int)" <<endl;
        float y = x;
        return y;
    }
    #endif
	virtual
	int func(float x)
	{
		cout << "Sub::func(int)" <<endl;
		float y = x;
		return y;
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
	test(sub);//通过虚函数调用,发生了虚函数机制

	sub.func(5);//通过对象的方式进行调用时，虚函数机制不会激活,隐藏
	
	return 0;
}
