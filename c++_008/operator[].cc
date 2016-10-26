 ///
 /// @file    operator[].cc
 /// @author  lemon(haohb13@gmail.com)
 /// @date    2016-10-25 10:09:58
 ///
 
#include <string.h>
#include <iostream>
using std::cout;
using std::endl;


class CharArr
{
public:
	CharArr(int size)
	: _size(size)
	, _pbuf(new char[_size])
	{
		
	}

	~CharArr()
	{
		delete [] _pbuf;
	}

	int size()
	{	return _size;	}

	char & operator[](int idx);
private:
	int _size;
	char * _pbuf;
};


//下标访问运算符的参数类型是任意的
char & CharArr::operator[](int idx)
{
	static char nullchar = '\0';
	if(idx >=0 && idx < _size)
		return _pbuf[idx];
	else
	{
		cout << "下标越界" << endl;
		return nullchar;
	}
}


int main(void)
{
	const char * pstr = "hello,world!";//文字常量区
	int len = strlen(pstr) + 1;

	CharArr ca(len);
	for(int idx = 0; idx != len; ++idx)
	{	ca[idx] = pstr[idx];	}
//	int idx;
	for(int idx = 0; idx != ca.size(); ++idx)
	{
		cout << ca[idx];
	}
//		cout << ca[idx];
	cout << endl;

	return 0;
}
