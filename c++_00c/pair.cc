 ///
 /// @file    pair.cc
 /// @author  lemon(haohb13@gmail.com)
 /// @date    2016-10-31 15:24:20
 ///
 
#include <iostream>
#include <utility>
#include <string>
using std::cout;
using std::endl;
using std::pair;
using std::string;


int main(void)
{
	pair<int, string> t(600036, "招商银行");

	cout << t.first << "--->" << t.second << endl;

	return 0;
}
