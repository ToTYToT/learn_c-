 ///
 /// @file    map3.cc
 /// @author  lemon(haohb13@gmail.com)
 /// @date    2016-10-31 16:34:56
 ///
 
#include <iostream>
#include <map>
#include <string>
using std::cout;
using std::endl;
using std::map;
using std::multimap;
using std::string;
using std::pair;

template <typename Container>
void display(const Container & c)
{
	typename Container::const_iterator it = c.begin();
	for(; it != c.end(); ++it)
	{
		cout << it->first << " ---> "
			 << it->second << endl;
	}
}


int main(void)
{
	pair<int, string> arr[4] = {
		pair<int, string>(1, "A"),
		pair<int, string>(2, "B"),
		pair<int, string>(3, "C"),
		pair<int, string>(3, "D"),
	};

	map<int, string> mapIntStr(arr, arr + 4);

	display(mapIntStr);
	mapIntStr.erase(1);
	cout << "删除关键字为1的元素之后:" << endl;
	display(mapIntStr);
	


	cout << endl;


	multimap<int, string> mmapIntStr(arr, arr + 4);
	display(mmapIntStr);

	mmapIntStr.erase(3);
	cout << "删除关键字为3的元素之后:" << endl;
	display(mmapIntStr);


	return 0;
}
