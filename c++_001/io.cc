 ///
 /// @file    io.cc
 /// @author  lemon(haohb13@gmail.com)
 /// @date    2016-10-17 17:13:19
 ///
 
#include <iostream>
#include <string>
using std::cin;
using std::cout;
using std::endl;
using std::string;


int main(void)
{
	int num;
	cin >> num;
	cout << "num = " << num << endl;

#if 1
	string s1;
	cin >> s1;
	cout << "s1 = " << s1 << endl;
#endif

#if 1
	//string s1;
	while(getline(cin, s1))
	{
		cout << "s1 = " << s1 << endl;
	}
#endif
}
