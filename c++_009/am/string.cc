 ///
 /// @file    string.cc
 /// @author  lemon(haohb13@gmail.com)
 /// @date    2016-10-27 11:37:55
 ///
 
#include <stdio.h>
#include <iostream>
#include <string>
using std::cout;
using std::endl;
using std::string;



int main(void)
{
	string s1 = "hello";
	string s2 = s1;
	string s3 = s1;

	printf("&s1 = %p\n", s1.c_str());
	printf("&s2 = %p\n", s2.c_str());
	printf("&s3 = %p\n", s3.c_str());

	cout << "s1[0] = " << s1[0] << endl;
	printf("&s1 = %p\n", s1.c_str());
	printf("&s2 = %p\n", s2.c_str());
	printf("&s3 = %p\n", s3.c_str());

	char & ch = s1[0];
	ch = 'H';

	return 0;
}
