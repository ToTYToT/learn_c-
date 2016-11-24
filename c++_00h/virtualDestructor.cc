 ///
 /// @file    virtualDestructor.cc
 /// @author  lemon(haohb13@gmail.com)
 /// @date    2016-11-08 16:14:59
 ///
 
#include <iostream>
using std::cout;
using std::endl;


class Base
{
public:
	Base()
	: _pdata(new char[64])
	{
		cout << "Base()" << endl;
	}

	virtual
	~Base()
	{
		cout << "~Base()" << endl;
		delete [] _pdata;
	}
private:
	char * _pdata;
};


class Child : public Base
{
public:
	Child()
	: Base()
	, _pCdata(new char[64])
	{
		cout << "Child()" << endl;
	}

	~Child()
	{
		cout << "~Child()" << endl;
		delete [] _pCdata;
	}
private:
	char * _pCdata;
};

int main(void)
{
	cout << "sizeof(Child) = " << sizeof(Child) << endl;
	Base * pbase = new Child;

	delete pbase;

	return 0;
}
