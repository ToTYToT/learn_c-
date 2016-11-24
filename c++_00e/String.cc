 ///
 /// @file    String.cc
 /// @author  lemon(haohb13@gmail.com)
 /// @date    2016-11-04 14:42:04
 ///
 
#include <string.h>
#include <iostream>
#include <vector>
using std::cout;
using std::endl;
using std::vector;



class String
{
public:
	String()
	: _pstr(new char[1])
	{
		cout << "String()" << endl;
	}

	String(const char * str)
	: _pstr(new char [strlen(str) + 1])
	{
		strcpy(_pstr, str);
		cout << "String(const char * )" << endl;
	}

	//const引用是不能判断传递过来的实参是左值还是右值
	//复制构造函数
	String(const String & rhs)
	: _pstr(new char[strlen(rhs._pstr) + 1])
	{
		strcpy(_pstr, rhs._pstr);
		cout << "String(const String & )" << endl;
	}
	
	//移动构造函数, c++11
	//如果传递过来的是右值，会优先调用移动构造函数
	String(String && rhs)
	: _pstr(rhs._pstr)
	{
		rhs._pstr = nullptr;
		cout << "String(String && rhs)" << endl;
	}

	~String()
	{
		delete [] _pstr;
		cout << "~String()" << endl;
	}

	//赋值运算符函数
	String & operator=(const String & rhs)
	{
		cout << "String & operator=(const String &)" << endl;
		if(&rhs != this)
		{
			delete [] _pstr;
			_pstr = new char[strlen(rhs._pstr) + 1];
			strcpy(_pstr, rhs._pstr);
		}
		return *this;
	}

	//移动赋值运算符函数
	String & operator=(String && rhs)
	{
		cout << "String & operator=(String && rhs)" << endl;
		char * tmp=_pstr;
        _pstr=rhs._pstr;
        rhs._pstr = tmp;
		return *this;
	}

	String && func()
	{
	
	}


	friend std::ostream & operator <<(std::ostream & os, const String & rhs);
private:
	char * _pstr;
};

std::ostream & operator <<(std::ostream & os, const String & rhs)
{
	os << rhs._pstr;
	return os;
}


int test0(void)
{
#if 1
	String s1 = "hello";
	cout << "s1 = " << s1 << endl;

	String s2("world");
	cout << "s2 = " << s2 << endl;
	cout << endl;
#endif

	String s3 = String("shenzhen");
	cout << "s3 = " << s3 << endl;
	cout << endl;

	s3 = "wangdao";
	cout << "s3 = " << s3 << endl;

	
	return 0;
}

int test1(void)
{
	int a = 1;
	const int & ref1 = a;//常量左值引用能绑定到所有类型的值
	const int & ref2 = 1;
	int && rref = 1;
//	int && rref2 = a;//右值引用不能绑定到左值
}

int main(void)
{
	test0();
	return 0;
}
