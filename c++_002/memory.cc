 ///
 /// @file    memory.cc
 /// @author  lemon(haohb13@gmail.com)
 /// @date    2016-10-18 10:18:29
 ///
 
#include <stdio.h>
#include <string.h>
#include <iostream>
using std::cout;
using std::endl;

int a = 0;
char * p1;
const int d = 100;//文字常量区

int main(void)
{
	int b;
	char s[] = "123456";
	char * p2;
	char * p3 = "123456";
	static int c = 0;
	p1 = new char[10];
	p2 = new char[5];
	strcpy(p1, "123456");
	const int e = 10;//栈区

	printf("&a = %p\n", &a);
	printf("&p1 = %p\n", &p1);
	printf("&d = %p\n", &d);
	printf("&e = %p\n", &e);

	printf("&b = %p\n", &b);
	printf("s = %p\n", s);
	printf("&p2 = %p\n", &p2);
	printf("&p3 = %p\n", &p3);
	printf("p3 = %p\n", p3);
	printf("&c = %p\n", &c);
	printf("p1 = %p\n", p1);
	printf("p2 = %p\n", p2);
	cout << endl;

//	*p3 = 'h';//试图修改文字常量区的内容,Error
//	printf("p3 = %s\n", p3);

	return 0;
}
