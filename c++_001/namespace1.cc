 ///
 /// @file    namespace1.cc
 /// @author  lemon(haohb13@gmail.com)
 /// @date    2016-10-17 11:31:45
 ///
 
#include <iostream>

using namespace std;


namespace A
{
void displayA() 
{ 
	cout << "displayA()" << endl; 
}

}// end of namespace A

namespace B
{
void displayB()
{
	A::displayA();//可见域
	cout << "displayB()" << endl;
} 
}// end of namespace B


int main(void)
{
	//A::displayA();
	A::displayA();
	B::displayB();

	return 0;
}
