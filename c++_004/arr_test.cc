 ///
 /// @file    arr_test.cc
 /// @author  ToTYToT(hongzimeng@foxmail.com)
 /// @date    2016-10-20 14:42:41
 ///
#include <vector>
#include <iostream>
using std::cout;
using std::endl;
using std::vector;

void printVector(vector<int>&vec)
{
	cout<<"verInt"<<vec.size()<<endl;
	cout<<"verInt"<<vec.capacity()<<endl;
	cout<<endl;
}
int main()
{
	vector<int>verInt;//动态扩容
	printVector(verInt);
	verInt.push_back(0);
	printVector(verInt);
	verInt.push_back(1);
	printVector(verInt);
	verInt.push_back(2);
	printVector(verInt);
	verInt.push_back(3);
	printVector(verInt);
	verInt.push_back(4);
	printVector(verInt);
	verInt.push_back(5);
	printVector(verInt);
	verInt.push_back(6);
	printVector(verInt);
	verInt.push_back(7);
	printVector(verInt);
    vector<int>verI;	
	cout<<endl;
#if 0
    vector<int>::iterator it =verInt.begin();
	for(;it!=verInt.end();++it)
	{
		cout<< *it<<endl;
	}
	cout<<endl;
#endif

    for(auto&ielem:verInt)//auto the values or class 类型
    {
    	cout<<ielem<<endl;
        for(auto & elem:verI)
        {
    	    cout<<elem<<endl;
        }
    }
	return 0;
}


