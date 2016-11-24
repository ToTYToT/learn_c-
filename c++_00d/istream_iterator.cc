 ///
 /// @file    istream_iterator.cc
 /// @author  lemon(haohb13@gmail.com)
 /// @date    2016-11-01 10:25:50
 ///
 
#include <iostream>
#include <iterator>
#include <vector>
#include <algorithm>
using std::cout;
using std::endl;
using std::vector;

int main(void)
{
	vector<int> vecInt;
	std::istream_iterator<int> isi(std::cin);
	copy(isi, std::istream_iterator<int>(), std::back_inserter(vecInt));
	//copy(isi, std::istream_iterator<int>(), std::front_inserter(vecInt));
	
	for(auto & elem : vecInt)
	{
		cout << elem << " ";
	}
	cout << endl;

	return 0;
}

