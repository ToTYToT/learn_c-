 ///
 /// @file    String.cc
 /// @author  lemon(haohb13@gmail.com)
 /// @date    2016-10-19 15:16:56
 ///
 
#include <string.h>
#include <iostream>
using std::cout;
using std::endl;


class String
{
public:
	String()
	: _pstr(new char[1])
	{
		cout << "String()" << endl;
	}

	String(const char * pstr)
	: _pstr(new char[strlen(pstr) + 1])
	{
		cout << "String(const char *)" << endl;
		strcpy(_pstr, pstr);
	}

	String(const String & rhs)
	: _pstr(new char[strlen(rhs._pstr) + 1])
	{
		cout << "String(const String &)" << endl;
		strcpy(_pstr, rhs._pstr);
	}

#if 0
	//版本2 
	String & operator=(const String & rhs)
	{
		if(this != &rhs)
		{
			char *ptmp = new char [strlen(rhs._pstr) + 1];
			if(ptmp)
			{
				strcpy(ptmp, rhs._pstr);
				delete [] _pstr;
				//_pstr = new char[strlen(rhs._pstr) + 1];//有异常安全的风险
				_pstr = ptmp;
			}
		}
		return *this;
	}
#endif

	//版本3-->高级版本  
	String & operator=(const String & rhs)
	{
		if(this != &rhs)
		{
			String tmp(rhs);//
			char * p = _pstr;
			_pstr = tmp._pstr;
			tmp._pstr = p;
		}
		return *this;
	}

	~String()
	{
		cout << "~String()" << endl;
		delete [] _pstr;
	}

	void print()
	{
		cout << _pstr << endl;
	}
private:
	char * _pstr;
};

int main(void)
{
	String str1;
	str1.print();

	String str2("hello,world");
	str2.print();

	String str3 = "wangdao";
	str3.print();

	str2 = str3;
	str2.print();

	return 0;
}

