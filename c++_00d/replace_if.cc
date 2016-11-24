 ///
 /// @file    replace_if.cc
 /// @author  lemon(haohb13@gmail.com)
 /// @date    2016-11-01 11:20:54
 ///
 
#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>
using std::cout;
using std::endl;
using std::vector;
using std::ostream_iterator;


int main(void)
{
	vector<int> vecInt{1, 2, 3, 4, 5, 6};
	std::less<int> lt;
	replace_if(vecInt.begin(), vecInt.end(), bind2nd(lt, 3), 7);

	ostream_iterator<int> osi(cout, "\n");
	copy(vecInt.begin(), vecInt.end(), osi);

	return 0;
}
