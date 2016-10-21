 ///
 /// @file    io1.cc
 /// @author  lemon(haohb13@gmail.com)
 /// @date    2016-10-20 11:38:48
 ///
 
#include <iostream>
#include <string>
#include <limits>
using std::cin;
using std::cout;
using std::endl;
using std::string;


void printCin()
{
	cout << "cin's badbit  = " << cin.bad() << endl;
	cout << "cin's failbit = " << cin.fail() << endl;
	cout << "cin's eofbit  = " << cin.eof() << endl;
	cout << "cin's goodbit = " << cin.good() << endl;
}

int test1(void)
{
	int num;
	printCin();

	while(cin >> num)
	{
		cout << "num = " << num << endl;
	}

	cout << endl;
	printCin();

	cin.clear();//重置流的状态
	cout << endl;
	printCin();

	cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');//清空缓冲区

	string s; 
	cin >> s;// 输入流是有缓冲区的
	cout << "s = " << s << endl;

	return 0;
}


void test2()
{
	int ival;
	while(cin >> ival, !cin.eof()) //Ctrl + d 代表输入结束
	{
		if(cin.bad())
		{
			cout << "IO stream corrupted!" << endl;
			return ;
		}
		if(cin.fail())
		{
			cin.clear();
			cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			cout << "data illegal, try again!" << endl;
			continue;
		}
		cout << "ival = " << ival << endl;
	}
	return ;
}

int main(void)
{
	test2();
//	test1();

	return 0;
}

