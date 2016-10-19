 ///
 /// @file    bool.cc
 /// @author  lemon(haohb13@gmail.com)
 /// @date    2016-10-17 16:42:32
 ///
 
#include <iostream>
using std::cout;
using std::endl;


//非0代表正确， 0代表错误

int main(void)
{
	//_Bool //C99

	bool b1 = 100;
	bool b2 = 1;
	bool b3 = 0;
	bool b4 = true;
	bool b5 = false;

	cout << "b1 = " << b1 << endl;
	cout << "b2 = " << b2 << endl;
	cout << "b3 = " << b3 << endl;
	cout << "b4 = " << b4 << endl;
	cout << "b5 = " << b5 << endl;

	cout << "sizeof(bool) = " << sizeof(bool) << endl;

	return 0;
}

