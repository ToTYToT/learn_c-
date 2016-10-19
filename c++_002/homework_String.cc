 ///
 /// @file    homework_String.cc
 /// @author  ToTYToT(hongzimeng@foxmail.com)
 /// @date    2016-10-19 10:23:45
 ///
#include <string.h> 
#include <iostream>
using std::cout;
using std::endl;

class String
{
	public:
		String();
		String(const char *pstr);
#if 1
		String(const String & rhs)
		:_pstr(new char[strlen(rhs._pstr)+1])
		{
			cout << "String(const String & rhs)" << endl;
			strcpy(_pstr,rhs._pstr);
		}
#endif

#if 1
		String & operator=(const String & rhs)
		{
			if(this != &rhs)
			{
				cout << "String & operator=(const String & rhs)" << endl;
				delete [] _pstr;
				_pstr=new char[strlen(rhs._pstr)+1];
				strcpy(_pstr,rhs._pstr);
			}
			return *this;
		}
#endif

		~String();

		void print();

	private:
		char * _pstr;
};

#if 1
String::String()
: _pstr(new char [0])
{
	cout << "String()" << endl;
//	String
}
#endif

//#if 1
String::String(const char*pstr)
: _pstr(new char[strlen(pstr)+1])
{
	cout << "String(const char *pstr)" << endl;
	strcpy(_pstr,pstr);
}
//#endif

#if 1
String::~String()
{
	cout << "~String()" << endl;
	delete [] _pstr;
}
#endif

#if 1
void String::print()
{
	cout << "print()" << endl;
	cout << _pstr << endl;
}
#endif

int main(void)
{
	String str1;
	str1.print();

	String str2 = "Hello,world";
	String str3 = "wangdao";

	str2.print();
	str3.print();
	str2 = str3;
	str2.print();

	String str4 = str3;
	str4.print();
	return 0;
}
//第一次运行结果：
//String()
//print()
//▒▒▒▒9▒u▒▒
//[^_]Ív
//String(const char *pstr)
//String(const char *pstr)
//print()
//Hello,world
//print()
//wangdao
//print()
//wangdao
//String(const String & rhs
//print()
//wangdao
//~String()
//~String()
//~String()
//~String()
//Segmentation fault (core dumped)
//
//第二次运行结果，在无参构造函数中为_pstr申请了0个字节的空间:
//String()
//print()
//
//String(const char *pstr)
//String(const char *pstr)
//print()
//Hello,world
//print()
//wangdao
//print()
//wangdao
//String(const String & rhs
//print()
//wangdao
//~String()
//~String()
//~String()
//~String()
//
//第三次运行结果，(在operator函数中加入打印函数名称):
//String()
//print()
//
//String(const char *pstr)
//String(const char *pstr)
//print()
//Hello,world
//print()
//wangdao
//String & operator+(const String & rhs)
//print()
//wangdao
//String(const String & rhs)
//print()
//wangdao
//~String()
//~String()
//~String()
//~String()
//
