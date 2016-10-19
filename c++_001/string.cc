 ///
 /// @file    string.cc
 /// @author  lemon(haohb13@gmail.com)
 /// @date    2016-10-17 16:47:04
 ///
 
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <iostream>
#include <string>
using std::cout;
using std::endl;
using std::string;


void test1()
{
	char str1[] = "hello,world";
	printf("%s\n", str1);
	char str2[] = "shenzhen";

	char * pstr = (char *)malloc(strlen(str1) + strlen(str2) + 1);
	strcpy(pstr, str1);
	strcat(pstr, str2);

	printf("%s\n", pstr);


	char * p = strstr(pstr, "world");
	char buff[128];
	strncpy(buff, p, 5);
	printf("%s\n", buff);

	free(pstr);
}

void test2()
{
	string s1 = "hello,world";
	string s2 = "shenzhen";
	string s3 = s1 + s2;
	cout << s3 << endl;

	cout << "s3.size() = " << s3.size() << endl;

	string s4 = s3.substr(s3.find("world"), 5);
	cout << s4 << endl;

	cout << s1[0] << endl;//类似于数组

	for(int idx = 1; idx != s1.size(); ++idx)
	{
		cout << s1[idx] << endl;
	}

	cout << endl;
	//迭代器的方式，类似于指针
	string::iterator it = s1.begin();
	for(;it != s1.end(); ++it)
	{
		cout << *it << endl;
	}
}

int main(void)
{
	//test1();
	test2();
}
