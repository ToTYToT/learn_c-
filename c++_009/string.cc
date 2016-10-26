 ///
 /// @file    string.cc
 /// @author  lemon(haohb13@gmail.com)
 /// @date    2016-10-26 14:42:43
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
	cout << "s1 = " << s1 << endl;
	cout << "s2 = " << s2 << endl;
	cout << "s3 = " << s3 << endl;
	
	printf("s1's address : %p\n", s1.c_str());
	printf("s2's address : %p\n", s2.c_str());
	printf("s3's address : %p\n", s3.c_str());

	s1[0] = 'X';
	cout << "修改之后:" << endl;

	cout << "s1 = " << s1 << endl;
	cout << "s2 = " << s2 << endl;
	cout << "s3 = " << s3 << endl;
	
	printf("s1's address : %p\n", s1.c_str());
	printf("s2's address : %p\n", s2.c_str());
	printf("s3's address : %p\n", s3.c_str());
	return 0;
}
