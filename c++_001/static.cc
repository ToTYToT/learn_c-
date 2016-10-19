 ///
 /// @file    static.cc
 /// @author  lemon(haohb13@gmail.com)
 /// @date    2016-10-17 16:09:18
 ///
 
#include <iostream>
using std::cout;
using std::endl;


int test(void)
{
	double d1 = 5.5;
	int i1 = (int)d1;
	cout << "i1 = " << i1 << endl;

	int i2 = int(d1);
	cout << "i2 = " << i2 << endl;
	return 0;
}

int main(void)
{
	double d1 = 5.5;
	int i1 = static_cast<int>(d1);
	cout << "i1 = " << i1 << endl;

	//const_cast/dynamic_cast/reinterpret_cast

	return 0;
}

