 ///
 /// @file    copyControl1.cc
 /// @author  lemon(haohb13@gmail.com)
 /// @date    2016-11-07 15:10:20
 ///
 
#include <string.h>
#include <iostream>
using std::cout;
using std::endl;


class Base
{
public:
	Base(const char * pstr)
	: _pstr(new char [strlen(pstr) + 1])
	{
		cout << "Base(const char *)" << endl;
		strcpy(_pstr, pstr);
	}

	Base(const Base & rhs)
	: _pstr(new char [strlen(rhs._pstr) + 1])
	{
		cout << "Base(const Base &)" << endl;
		strcpy(_pstr, rhs._pstr);
	}

	Base & operator=(const Base & rhs)
	{
		cout << "Base & operator=(const Base&)" << endl;
		if(this != &rhs)
		{
			delete [] _pstr;
			_pstr = new char [strlen(rhs._pstr) + 1];
			strcpy(_pstr, rhs._pstr);
		}
		return *this;
	}

	void display()
	{
		cout << _pstr << endl;
	}

	~Base()
	{
		cout << "~Base()" << endl;
		delete [] _pstr;
	}

private:
	char * _pstr;
};

//当派生类没有定义复制控制函数时，而基类显式定义了复制控制函数
//派生类对象进行复制时，会自动调用基类的复制控制函数
class Derived : public Base
{
public:
#if 1	
    Derived(const char * pstr)
	: Base(pstr)
	{
		cout << "Derived(const char *)" << endl;
	}
#endif

private:
    char * _pstr;
};


int main(void)
{
	Derived d1("hello");
	d1.display();
	Derived d2(d1);
	d2.display();
	cout << endl;

	Derived d3(" world");
	d3.display();
	d1 = d3;
	d1.display();

	return 0;
}
