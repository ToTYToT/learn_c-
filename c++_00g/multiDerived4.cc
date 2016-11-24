 ///
 /// @file    multiDerived4.cc
 /// @author  lemon(haohb13@gmail.com)
 /// @date    2016-11-07 11:23:39
 ///
 
#include <iostream>
using std::cout;
using std::endl;


class A
{
public:
	A(){	cout << "A()" << endl;	}
	~A(){	cout << "~A()" << endl;	}
};

class B
{
public:
	B(){	cout << "B()" << endl;	}
	~B(){	cout << "~B()" << endl;	}
};
class C
{
public:
	C(){	cout << "C()" << endl;	}
	~C(){	cout << "~C()" << endl;	}
};
class D : public A, public B, public C
{
public:
	D()
	: A()
	, B()
	, C()
	{	cout << "D()" << endl;	}

	~D(){	cout << "~D()" << endl;	}
};


int main(void)
{
	D d;
	return 0;
}
