 ///
 /// @file    template1.cc
 /// @author  lemon(haohb13@gmail.com)
 /// @date    2016-10-29 09:54:10
 ///
 
#include <stdio.h>
#include <string.h>
#include <iostream>
#include <string> 
using std::cout;
using std::endl;
using std::string;

#if 1
template <typename T>
T add(const T & a, const T & b)
{
	return a + b;
}
#endif

//模板特化(template specialization)
template <>
const char * add(const char * const & a, const char * const & b)
{
	char * ptmp = new char[strlen(a) + strlen(b) + 1];
	strcpy(ptmp, a);
	strcat(ptmp, b);
	return ptmp;
}


//函数模板的一个特例
#if 0
char * add(char * const & a, char * const & b)
{
	char * ptmp = new char[strlen(a) + strlen(b) + 1];
	strcpy(ptmp, a);
	strcat(ptmp, b);
	return ptmp;
}
#endif

#if 0
int add(const int & a, const int & b)
{
	return a + b;
}

double add(const double & a, const double & b)
{
	return a + b;
}

char * add(const char *& a, const char *& b)
{
	return a + b;
}
#endif


int main(void)
{
	//cout << add(10, 20) << endl;//隐式实例化
	//cout << add(1.0, 2.0) << endl;
	const char * buf1 = "hello";
	const char * buf2 = "world";
	cout << add(buf1, buf2) << endl; 
	return 0;
}
