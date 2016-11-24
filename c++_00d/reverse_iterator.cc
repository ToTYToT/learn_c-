 ///
 /// @file    reverse_iterator.cc
 /// @author  lemon(haohb13@gmail.com)
 /// @date    2016-11-01 15:18:38
 ///
 
#include <iostream>
#include <vector>
#include <iterator>
#include <algorithm>
using std::cout;
using std::endl;
using std::vector;
using std::ostream_iterator;


int main(void)
{
	vector<int> vecInt{1, 2, 3, 4, 5, 6};
	ostream_iterator<int> osi(cout, "\n");
    vector<int>::iterator it=vecInt.begin();	
	copy(it, vecInt.end(), osi);
	vector<int>::reverse_iterator rit = vecInt.rbegin();
	copy(rit, vecInt.rend(), osi);

	return 0;
}
