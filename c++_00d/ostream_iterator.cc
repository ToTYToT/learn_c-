 ///
 /// @file    ostream_iterator.cc
 /// @author  lemon(haohb13@gmail.com)
 /// @date    2016-11-01 10:17:58
 ///
 
#include <iostream>
#include <iterator>
#include <algorithm>
#include <vector>
using std::cout;
using std::endl;
using std::vector;


int main(void)
{
	vector<int> vecInt = {1, 2, 3, 4, 5, 6};

	//将标准输出流看成是一个容器
	std::ostream_iterator<int> osi(cout, " ");
	copy(vecInt.begin(), vecInt.end(), osi);

	cout << endl;

	return 0;
}
