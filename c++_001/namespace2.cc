 ///
 /// @file    namespace2.cc
 /// @author  lemon(haohb13@gmail.com)
 /// @date    2016-10-17 11:31:45
 ///
 
#include <iostream>

//using namespace std;//using编译指令,把名字空间里面所有的实体全部引入

using std::cout;
using std::endl;

namespace A
{
int num = 10;
void displayA() 
{ 
	cout << "displayA()" << endl; 
}

}// end of namespace A


//using A::displayA;//using声明机制

namespace B
{
int num = 100;

using A::displayA;//只在namespace B的范围内
void displayB()
{
	displayA();//可见域
	cout << "displayB()" << endl;
} 
}// end of namespace B


//using A::num;//不要出现这种情况
//using B::num;

int test(void)
{
	//A::displayA();
	A::displayA();
	B::displayB();

	num = 1000;

	return 0;
}

int main(void)
{
	test();
	return 0;
}
