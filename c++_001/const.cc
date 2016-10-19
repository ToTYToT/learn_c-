 ///
 /// @file    const.cc
 /// @author  lemon(haohb13@gmail.com)
 /// @date    2016-10-17 14:35:51
 ///
 
#include <iostream>
using std::cout;
using std::endl;

#define MAX 100 //简单的字符串的替换，没有类型检查
				//发生在预编译/预处理
const int Min = 100;

int main(void)
{
	const int a	= 1;//常量的值不能被修改
	cout << "a = " << a << endl;
	//a = 10;
	//const int b;//常量必须进行初始化
	
	//int * pa = &a;// 非const指针不能指向const变量
	
	const int * pa = &a;//指针所指向的变量是常量 -->常量指针 (pointer to const)
	//*pa = 10;//Error
	cout << "*pa = " << *pa << endl;

	int const * pb = &a;//与24行表达的意思相同
	//*pb = 10;//Error
	cout << "*pb = " << *pb << endl;

	int b = 2;
	cout << "b = " << b << endl;
	int * const pc = &b;
	//pc本身的值不能被修改的，指针不能改变其指向的
	//指针常量(const pointer)
	//函数指针 -- 指针函数, 数组指针 -- 指针数组
	

	*pc = 10;
	cout << "b = " << b << endl;
	cout << "*pc = " << *pc << endl;
	int c = 3;
	//pc = &c;//Error 不能被修改
	
	const int * const pd = &b;//两者都不能被修改
	//*pd = 100;
	//pd = &c;

	return 0;
}
