 ///
 /// @file    assosiativeContainer1.cc
 /// @author  lemon(haohb13@gmail.com)
 /// @date    2016-10-31 16:20:24
 ///
 
#include <iostream>
#include <map>
#include <string>
using std::cout;
using std::endl;
using std::map;
using std::multimap;
using std::pair;
using std::string;


int main(void)
{
	pair<int, string> arr[2] = {
		pair<int, string>(1, "A"),
		pair<int, string>(2, "B"),
	};

	map<int, string> mapIntStr(arr, arr + 2);
	pair<int, string> t(2, "X");

	pair<map<int, string>::iterator, bool>
		ret = mapIntStr.insert(t);

	if(ret.second)
	{
		cout << "数据插入成功" << endl;
	}
	else
	{
		cout << "map中已经包含了与t关键字相同的元素:" 
			 << ret.first->first << " ----> "
			 << ret.first->second << endl;
	}


	cout << endl;
	multimap<int, string> mmapIntStr(arr, arr + 2);
	multimap<int, string>::iterator mmret = mmapIntStr.insert(t);
	cout << mmret->first << " ---> " 
		 << mmret->second << endl;
	
	return 0;
}

