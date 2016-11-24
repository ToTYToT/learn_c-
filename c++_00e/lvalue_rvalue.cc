 ///
 /// @file    lvalue_rvalue.cc
 /// @author  lemon(haohb13@gmail.com)
 /// @date    2016-11-04 14:53:41
 ///
 
#include <iostream>
#include <vector>
#include <string>
using std::cout;
using std::endl;
using std::vector;
using std::string;


int main(void)
{
	int a = 1;
	int b = 120;
	int * pFlag = & a;
	vector<int> vecTemp;
	vecTemp.push_back(1);

	string s1 = "hello ";
	string s2 = "world";
	const int & m = 1;

	&a;//左值
	&b;//左值
	//&(a+b);//右值
	//&(a++);//右值
	&(++a);//左值

	&pFlag;
	&(*pFlag);

	&vecTemp[0];

	//&100;//字面值常量, 右值
	
	//&string("hello");//右值
	
	//&(s1 + s2);//右值
	
	&m;//左值
}
