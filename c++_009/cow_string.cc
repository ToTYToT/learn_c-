 ///
 /// @file    cow_string.cc
 /// @author  lemon(haohb13@gmail.com)
 /// @date    2016-10-26 14:56:59
 ///

#include <stdio.h>
#include <string.h>
#include <iostream>

using std::ostream;
using std::cout;
using std::endl;


class String
{
public:
	String();
	String(const char * rhs);
	String(const String & rhs);
	~String();

	String & operator=(const String & rhs);

	char & operator[](int idx);
	const char & operator[](int idx) const;

	int useCount()
	{	return _pstr[length() + 1];	}

	int length()
	{	return strlen(_pstr);	}

	const char * c_str() const
	{	return _pstr;	}
private:
	void initRefcount()
	{
		_pstr[length() + 1] = 1;
	}

	void increaseRefcount()
	{
		++_pstr[length() + 1];
	}

	void decreaseRefcount()
	{
		--_pstr[length() + 1];
	}


	friend ostream & operator<<(ostream & os, const String & rhs);
private:
	char * _pstr;
};

String::String()
: _pstr(new char[2])
{
	cout << "String()" << endl;
	initRefcount();
}

String::String(const char * rhs)
: _pstr(new char[strlen(rhs) + 2])
{
	cout << "String(const char *)" << endl;
	strcpy(_pstr, rhs);
	initRefcount();
}

String::String(const String & rhs)
: _pstr(rhs._pstr)
{
	cout << "String(const String & rhs)" << endl;
	increaseRefcount();
}

String & String::operator=(const String & rhs)
{
	if(this != &rhs)
	{
		//delete [] _pstr;	
		decreaseRefcount();
		if(useCount() == 0)
			delete [] _pstr;

		_pstr = rhs._pstr;
		increaseRefcount();
	}
	return *this;
}

String::~String()
{
	decreaseRefcount();
	if(useCount() == 0)
	{
		delete [] _pstr;
		cout << "~String()" << endl;
	}
}

//非const版本的下标访问运算符不能区分读操作还是写操作
//
char & String::operator[](int idx)
{
	static char nullchar = '\0';
	if(idx >= 0 && idx < length())
	{
		if(useCount() > 1) //针对写操作
		{
			decreaseRefcount();
			char * ptmp = new char[length() + 2];
			strcpy(ptmp, _pstr);
			_pstr = ptmp;
			initRefcount();
		}
		return _pstr[idx];
	}
	else
	{
		cout << "下标越界" << endl;
		return nullchar;
	}
}

const char & String::operator[](int idx) const
{
	return _pstr[idx];
}

ostream & operator<<(ostream & os, const String & rhs)
{
	os << rhs._pstr;
	return os;
}
int main(void)
{
	String s1 = "hello";
	String s2 = s1;
	
	cout << "s1 = " << s1 << endl;
	cout << "s1's useCount = " << s1.useCount() << endl;

	String s3 = "world";
	String s4 = s3;
	String s5 = s3;

	cout << "s3's useCount = " << s3.useCount() << endl;
	cout << "s3 = " << s3 << endl;

	cout << endl;
	cout << "发生赋值之后:" << endl;
	s3 = s1;
	cout << "s1 = " << s1 << endl;
	cout << "s3 = " << s3 << endl;
	cout << "s1's useCount = " << s1.useCount() << endl;
	cout << "s4's useCount = " << s4.useCount() << endl;

	cout << endl;
	cout << "发生写操作之后:" << endl;
	s3[0] = 'X';
	cout << "s3 = " << s3 << endl;
	cout << "s1 = " << s1 << endl;
	cout << "s1's useCount = " << s1.useCount() << endl;
	cout << "s3's useCount = " << s3.useCount() << endl;
	printf("s1's address = %p\n", s1.c_str());
	printf("s2's address = %p\n", s2.c_str());

	cout << endl;
	cout << "发生读操作:" << endl;
	cout << s1[0] << endl;
	cout << "s1 = " << s1 << endl;
	cout << "s2 = " << s2 << endl;
	cout << "s1's useCount = " << s1.useCount() << endl;
	cout << "s2's useCount = " << s2.useCount() << endl;
	printf("s1's address = %p\n", s1.c_str());
	printf("s2's address = %p\n", s2.c_str());

	
	return 0;
}
