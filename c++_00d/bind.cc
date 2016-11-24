 ///
 /// @file    bind.cc
 /// @author  lemon(haohb13@gmail.com)
 /// @date    2016-11-01 16:05:05
 ///
 
#include <iostream>
#include <functional>
using std::cout;
using std::endl;
using std::bind;


int func(int x, int y)
{
	cout << "int func(int,int)" << endl;
	return x + y;
}

class A
{
public:
	int func(int x, int y)
	{
		cout << "A::func(int,int)" << endl;
		return x + y;
	}
};


int test(void)
{
	//bind函数可以改变原来函数的参数个数
	using namespace std::placeholders;
	//绑定2个参数
	auto f1 = bind(func, 10, 20);
	cout << f1() << endl;
	
	//绑定1个参数, 函数的其它参数必须使用占位符占据位置
	auto f2 = bind(func, 10, _1);
	cout << f2(10) << endl;
	auto f3 = bind(func, _1, 5);
	cout << f3(20) << endl;

	A a;
	//bind还可以绑定到成员函数
	auto f4 = bind(&A::func, &a, _1, 100);
	cout << f4(1) << endl;

	//传递a时,会对对象a进行复制,一般不推荐这样做
	auto f5 = bind(&A::func, a, _1, 100);
	cout << f5(2) << endl;
	return 0;
}

struct Foo
{
	int data;
};


void f(int n1, int n2, int n3, const int & n4, int n5)
{
	cout << "(" << n1 
		 << "," << n2
		 << "," << n3
		 << "," << n4
		 << "," << n5
		 << ")" << endl;
}
int main(void)
{
	using namespace std::placeholders;

	int n = 7;
	//const int & x = n;
	//1. 占位符本身所占的位置是形参的位置
	//2. 占位符的数字代表的是实参传递时的位置
	//3. bind提前绑定的参数采用的是值传递(复制)
	//4. 在传递实参时,传递参数的个数是不受限制的
	//	 但传递的有可能是无效参数
	
    auto f1 = bind(f, _3, _4, _2, std::cref(n), _1);
	n = 10;
	f1(1,2,3,4,5,6, 8, 1001, 100, 101, 102);
	//n = 10;

	auto f2 = bind(&Foo::data, _1);
	Foo foo;
	foo.data = 10;
	cout << f2(foo) << endl;

	return 0;
}
