 ///
 /// @file    vector.cc
 /// @author  lemon(haohb13@gmail.com)
 /// @date    2016-10-20 14:38:17
 ///
 
#include <iostream>
#include <vector>
using std::cout;
using std::endl;
using std::vector;

void printVector(vector<int> & vec)
{
	cout << "vecInt's size = " << vec.size() << endl;
	cout << "vecInt's capacity = " << vec.capacity() << endl;
}

int main(void)
{
	//int arr[10];//拥有固定元素的数组
	
	//动态数组, 动态扩展容量
	//当元素的数量与capacity的数量相等，并且有新元素添加时
	//先开辟2 * capacity的空间，然后再将原来的元素copy到新开辟的空间
	//最后将新元素添加到新开辟空间，并且释放原来的空间
	vector<int> vecInt;
	//vecInt.reserve(1000);
	printVector(vecInt);

	vecInt.push_back(1);
	printVector(vecInt);

	vecInt.push_back(2);
	printVector(vecInt);

	vecInt.push_back(3);
	printVector(vecInt);

	vecInt.push_back(4);
	printVector(vecInt);

	vecInt.push_back(5);
	printVector(vecInt);

	vecInt.push_back(6);
	printVector(vecInt);

	for(size_t idx = 0; idx != vecInt.size(); ++idx)
	{
		cout << vecInt[idx] << endl;
	}
	cout << endl;

	vector<int>::iterator it = vecInt.begin();
	for(; it != vecInt.end(); ++it)
	{
		cout << *it << endl;
	}

	cout << endl;
	for(auto & elem : vecInt) //auto关键字可以自动推导变量或者对象的类型
	{
		cout << elem << endl;
	}
	return 0;
}
