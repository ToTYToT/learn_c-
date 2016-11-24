 ///
 /// @file    sequenceContainer1.cc
 /// @author  lemon(haohb13@gmail.com)
 /// @date    2016-10-31 11:11:26
 ///
 
#include <iostream>
#include <vector>
#include <list>
#include <deque>

using std::cout;
using std::endl;
using std::vector;
using std::list;
using std::deque;


int main(void)
{
	vector<int> vecInt;
	cout << "vecInt的元素个数:" << vecInt.size() << endl;

	double arr[5] = {1, 2, 3, 4, 5};
	deque<double> dequeDb(arr, arr + 5);
	for(size_t idx = 0; idx != dequeDb.size(); ++idx)
	{
		cout << dequeDb[idx] << " ";
	}
	cout << endl;

	list<float> listFlt(3, 5);
	//listFlt[0];//不能使用随机访问迭代器
	
	list<float>::iterator lit = listFlt.begin();
	for(; lit != listFlt.end();
		  ++lit)
	{
		cout << *lit << endl;
	}

	return 0;
}

