 ///
 /// @file    copy_if.cc
 /// @author  lemon(haohb13@gmail.com)
 /// @date    2016-11-01 11:15:45
 ///
 
#include <iostream>
#include <algorithm>
#include <vector>
#include <iterator>
using std::cout;
using std::endl;
using std::vector;
using std::ostream_iterator;


bool func(int & elem)
{
	if(elem > 5)
		return true;
	else
		return false;
}

int main(void)
{
	vector<int> vecInt{1, 2, 3, 4, 5, 6, 7, 8, 9};

	ostream_iterator<int> osi(cout, "\n");
	copy_if(vecInt.begin(), vecInt.end(), osi, func);

	return 0;
}



