 ///
 /// @file    oversee.cc
 /// @author  lemon(haohb13@gmail.com)
 /// @date    2016-11-07 11:31:18
 ///
 
#include <iostream>
using std::cout;
using std::endl;


class A
{
public:
	
	void display()
	{	cout << "A::display(), A::_ix = " << _ix << endl;	}

	void display(int ix)
	{	
		_ix = ix;
		cout << "A::display(int), ix = " << ix << endl;	
	}
protected:
	int _ix;
};

class B : public A
{
public:
	#if 0
    void display()
	{	
		_ix = 100;//数据成员，一样会发生隐藏,只能看到本类的同名数据成员
		A::_ix = 22;
		cout << "B::display(), B::_ix = " << _ix <<endl;
	}
#endif	
	int _ix;
};


int main(void)
{
	B b;
	b.display();//形式上是一样的，发生了隐藏机制
	b.display(3);//通过对象去调用函数，参数不一样，一样看不到基类的同名函数
	b.A::display();


	return 0;
}
