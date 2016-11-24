 ///
 /// @file    insert_iterator.cc
 /// @author  lemon(haohb13@gmail.com)
 /// @date    2016-11-01 15:22:05
 ///
 
#include <iostream>
#include <vector>
#include <list>
#include <algorithm>
using std::cout;
using std::endl;
using std::vector;
using std::list;


template <typename Container>
void display(const Container & c)
{
	typename Container::const_iterator it = c.begin();
	while(it != c.end())
	{
		cout << *it << " ";
		++it;
	}
	cout << endl;
}


int main(void)
{
	vector<int> vecSrc{0, 1, 2};
	list<int> listDest;

	//尾部插入迭代器
	copy(vecSrc.begin(), vecSrc.end(),
		 std::back_insert_iterator<list<int> >(listDest));
	display(listDest);

	//头部插入迭代器
	copy(vecSrc.begin(), vecSrc.end(),
		 std::front_insert_iterator<list<int> >(listDest));
	display(listDest);

	//任意插入迭代器
	copy(vecSrc.begin(), vecSrc.end(),
        std::insert_iterator<list<int> >(listDest, ++listDest.begin()));
//		std::insert_iterator<list<int> >(listDest, listDest.begin()++));
	display(listDest);

	return 0;

}
