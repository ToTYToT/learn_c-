 ///
 /// @file    X.cc
 /// @author  lemon(haohb13@gmail.com)
 /// @date    2016-10-18 14:49:29
 ///
 
#include <iostream>
using std::cout;
using std::endl;


class X
{
public:
	//初始化的顺序不是由在初始化列表中的顺序决定的，
	//而是由在类中申明数据成员的顺序决定的
	X(int ix)
	: _iy(ix)
	, _ix(_iy)
	{
	}

	void print()
	{
		cout << "_ix = " << _ix << endl;
		cout << "_iy = " << _iy << endl;
	}
private:
	int _ix;
	int _iy;
};

int main(void)
{
	X x(10);
	x.print();
}


