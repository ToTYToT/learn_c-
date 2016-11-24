 ///
 /// @file    remove.cc
 /// @author  lemon(haohb13@gmail.com)
 /// @date    2016-11-01 11:37:36
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
	vector<int> vecInt = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
	vecInt[3] = vecInt[5] = vecInt[9] = 99;

	ostream_iterator<int> osi(cout, " ");
	copy(vecInt.begin(), vecInt.end(), osi);
	cout << endl;
    //cout<<vecInt.end();
    //cout<<remove(vecInt.begin(), vecInt.end(), 99)<<endl;//并没有直接删除元素
	copy(vecInt.begin(), vecInt.end(), osi);
    cout<<endl;
	//remove不直接删除元素,也是为了防止迭代器失效
	// remove-erase惯用法
	vecInt.erase(remove(vecInt.begin(), vecInt.end(), 99),
				 vecInt.end());
	copy(vecInt.begin(), vecInt.end(), osi);
	cout << endl;

}
