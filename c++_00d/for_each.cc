 ///
 /// @file    for_each.cc
 /// @author  lemon(haohb13@gmail.com)
 /// @date    2016-11-01 11:07:41
 ///
 
#include <iostream>
#include <algorithm>
#include <vector>
using std::cout;
using std::endl;
using std::vector;


void print(int & num)
{
	cout << num << endl;
}

struct Printer
{
	void operator()(int & num)
	{
		cout << num << endl;
	}
};

int main(void)
{
	vector<int> vecInt{1, 2, 3, 4, 5, 6};
	for_each(vecInt.begin(), vecInt.end(), Printer());//指定一个函数对象

	return 0;
}	
