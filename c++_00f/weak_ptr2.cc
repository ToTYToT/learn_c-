 ///
 /// @file    weak_ptr2.cc
 /// @author  lemon(haohb13@gmail.com)
 /// @date    2016-11-05 11:16:11
 ///
 
#include <iostream>
#include <memory>
using std::cout;
using std::endl;
using std::weak_ptr;
using std::shared_ptr;


class X
{
public:
	X()
	{
		cout << "X()" << endl;
	}
	~X()
	{
		cout << "~X()" << endl;
	}

	void func()
	{
		cout << "X::func()" << endl;
	}
};

int main(void)
{
	weak_ptr<X> p;//弱引用智能指针，解决强引用智能指针shared_ptr的循环应用的问题
				  //不能单独使用,它没有定义访问资源的方法
	{
		shared_ptr<X> p2(new X);
		cout << "p2's use_count = " << p2.use_count() << endl;

		p = p2;//并没有增加引用计数
		cout << "p2's use_count = " << p2.use_count() << endl;
	
		shared_ptr<X> p3 = p.lock();//将weak_ptr提升为shared_ptr,引用计数加1

		cout << "p2's use_count = " << p2.use_count() << endl;
		if(p3)
		{
			p3->func();//使用到了operator->()的重载形式
		}
		else
		{
			cout << "managed object is destroyed!" << endl;
		}
	}
	cout << endl;

	shared_ptr<X> p4 = p.lock();//提升失败
	if(p4)
	{
		p4->func();//使用到了operator->()的重载形式
	}
	else
	{
		cout << "managed object is destroyed!" << endl;
	}
	return 0;
}

