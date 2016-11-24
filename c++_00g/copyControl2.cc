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
	Base()
	: _pstr(new char[1])
	{
		cout << "Base()" << endl;
	}

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
		cout << _pstr;
	}

	~Base()
	{
		cout << "~Base()" << endl;
		delete [] _pstr;
	}

private:
	char * _pstr;
};

//当派生类有显式定义复制控制函数时，而基类也显式定义了复制控制函数
//派生类对象进行复制时，不会自动调用基类的复制控制函数，必须手动显式
//调用基类的复制控制函数
class Derived : public Base
{
public:
	Derived(const char * pstr, const char * pstr2)
#if 1
    : Base(pstr)
#endif
	, _pstr2(new char[strlen(pstr2) + 1])
	{
		cout << "Derived(const char *, const char *)" << endl;
		strcpy(_pstr2, pstr2);
	}

	Derived(const Derived & rhs)
	: Base(rhs)  //这个不能少, 显式调用基类复制构造函数
	, _pstr2(new char [strlen(rhs._pstr2) + 1])
	{
		cout << "Derived(const Derived&)" << endl;
		strcpy(_pstr2, rhs._pstr2);
	}

	Derived & operator=(const Derived & rhs)
	{
		cout << "Derived & operator=(const Derived &rhs)" << endl;
		if(this != &rhs)
		{
			Base::operator=(rhs);//显式调用基类的赋值运算符函数
			delete [] _pstr2;
			_pstr2 = new char[strlen(rhs._pstr2) + 1];
			strcpy(_pstr2, rhs._pstr2);
		}
		return * this;
	}

	void display()
	{
		Base::display();
		cout << _pstr2 << endl;
	}

private:
	char * _pstr2;
};


int main(void)
{
	Derived d1("hello", ",world");
	d1.display();
	Derived d2(d1);
	d2.display();
	cout << endl;

	Derived d3("shenzhen", ",qinghu");
	d3.display();
	d1 = d3;
	d1.display();

	return 0;
}
