 ///
 /// @file    multiDerived3.cc
 /// @author  lemon(haohb13@gmail.com)
 /// @date    2016-11-07 10:25:27
 ///
 
#include <iostream>
using std::cout;
using std::endl;

class A
{
public:
	A(int ix = 0) : _ix(ix)
	{
		cout << "A(int)" << endl;
	}

	void setx(int ix)
	{	_ix = ix;	}

	void display()
	{	cout << "A::_ix = " << _ix << endl;	}
private:
	int _ix;
};
#if 1
class B : virtual public A
{};

class C : virtual public A
{};

class D : public B, public C
{
};
#endif
#if 0
class B : public A
{};

class C : public A
{};

class D : public B, public C
{
};
#endif
int main(void)
{
	D d;//存储二义性的解决方案：虚继承
	d.B::display();
	d.C::display();
	d.display();

	cout << "sizeof(A) = " << sizeof(A) << endl;

	cout << "sizeof(B) = " << sizeof(B) << endl;
	cout << "sizeof(C) = " << sizeof(C) << endl;
	cout << "sizeof(D) = " << sizeof(D) << endl;
	return 0;
}
