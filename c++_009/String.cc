 ///
 /// @file    String.cc
 /// @author  lemon(haohb13@gmail.com)
 /// @date    2016-10-26 09:59:43
 ///
 

#include <string.h>
#include <iostream>


using std::ostream;
using std::istream;
using std::cin;
using std::cout;
using std::endl;

class String
{
	friend ostream & operator<<(ostream & os, const String & rhs);
	friend istream & operator>>(istream & is, String & rhs);
public:
	String();
	String(const char * pstr);
	String(const String & rhs);
	~String();

	String & operator=(const String & rhs);
	String & operator=(const char * rhs);


	String & operator+=(const String & rhs);
	String & operator+=(const char * rhs);
private:
	char * _pstr;
};

String::String()
: _pstr(new char[1])
{
	cout << "String()" << endl;
}

String::String(const char * pstr)
: _pstr(new char[strlen(pstr) + 1]) 
{
	strcpy(_pstr, pstr);//深拷贝
	cout << "String(const char *)" << endl;
}

String::String(const String & rhs)
: _pstr(new char[strlen(rhs._pstr) + 1])
{
	strcpy(_pstr, rhs._pstr);	
	cout << "String(const String &)" << endl;
}

String::~String()
{
	delete [] _pstr;
	cout << "~String()" << endl;
}

String & String::operator=(const String & rhs)
{
	//strcpy(_pstr, rhs._pstr);
	if(this != & rhs) //1. 自复制
	{
		delete [] _pstr;//2. 删除左操作数指针所指向的原来的空间
		_pstr = new char[strlen(rhs._pstr) + 1];//3. 再去复制右操作数的内容, 执行的是深拷贝
		strcpy(_pstr, rhs._pstr);
	}
	return *this;
}

String & String::operator=(const char * rhs)
{
	*this = String(rhs);
	return *this;
}

String & String::operator+=(const String & rhs)
{
	int size = strlen(_pstr) + strlen(rhs._pstr) + 1;
	char * tmp = new char [size];//1. 先开辟足够大的空间
	strcpy(tmp, _pstr);//2. 然后再把左操作数的内容复制过来
	strcat(tmp, rhs._pstr);//3. 最后再把右操作数的内容复制过来

	delete [] _pstr;//4. 释放左操作数原来开辟的空间
	_pstr = tmp;//5. 再将左操作数的指针指向最新开辟空间
	return *this;
}
// 代码复用
String & String::operator+=(const char * rhs)
{
	*this += String(rhs);
	return *this;
}

ostream & operator<<(ostream & os, const String & rhs)
{
	os << rhs._pstr;
	return os;
}

istream & operator>>(istream & is, String & rhs)
{
	char buff[65535];// 1. 先开辟一个缓冲区,栈空间
	memset(buff, 0, sizeof(buff));
	//is >> buff;
	is.getline(buff, sizeof(buff));//2. 考虑空格
	
	delete [] rhs._pstr;//3. 释放右操作数原来的空间
	rhs._pstr = new char[strlen(buff) + 1];
	strcpy(rhs._pstr, buff);//4. 再去进行深拷贝
	return is;
}

int main(void)
{
	String s1;
	cout << s1 << endl;

	String s2 = "hello";
	String s3 = "world";
	s2 += s3;

	//cout << s2 << endl;

	cin >> s2;
	cout << s2 << endl;
}
