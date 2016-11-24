 ///
 /// @file    function.cc
 /// @author  lemon(haohb13@gmail.com)
 /// @date    2016-11-15 09:43:22
 ///
 
#include <iostream>
#include <functional>
using std::cout;
using std::endl;
using std::function;
using std::bind;


int add(int x, int y)
{
	return x + y;
}

//C的方式，定义了一个函数指针
typedef int (*Function)(int,int);

struct Foo
{
	int add(int x, int y)
	{
		return x + y;
	}
};


int main(void)
{
	function<int(int,int)> f = add;
	cout << f(1, 2) << endl;

	Function f1 = add;
	cout << f1(1, 2) << endl;

	function<int(int,int)> f2 = bind(&Foo::add, Foo(), std::placeholders::_1,
			 std::placeholders::_2);
	cout << f2(4, 5) << endl;


	return 0;
}
