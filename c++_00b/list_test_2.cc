 ///
 /// @file    list_test_2.cc
 /// @author  ToTYToT(hongzimeng@foxmail.com)
 /// @date    2016-10-29 23:55:03
 ///

// list::max_size
#if 0
#include <iostream>
#include <list>

int main ()
{
    unsigned int i;
    std::list<int> mylist;

    std::cout << "Enter number of elements: ";
    std::cin >> i;
	std::cout<<mylist.size()<<std::endl;
    if (i<mylist.max_size()) mylist.resize(i);
    else std::cout << "That size exceeds the limit.\n";

    return 0;
}
//这里max_size()来检查resize需要的空间是否已经超过最大值
#endif

#if 1

#include <iostream>
#include <list>

int main ()
{
    std::list<int> first;
    std::list<int> second;

    first.assign (7,100);                      // 7个值为100的整数

    second.assign (first.begin(),first.end()); // 复制first

    int myints[]={1776,7,4};
    first.assign (myints,myints+3);            // 通过数组重新分配元素

    std::cout << "Size of first: " << int (first.size()) << '\n';
    std::cout << "Size of second: " << int (second.size()) << '\n';
    return 0;
}
#endif
