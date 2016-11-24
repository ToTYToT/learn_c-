 ///
 /// @file    map.cc
 /// @author  lemon(haohb13@gmail.com)
 /// @date    2016-10-31 15:27:43
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


int main(void)
{
	pair<int, string> t(9, "Asia");
	pair<int, string> arrPairs[4] = {
		pair<int, string>(9, "Asia"),
		pair<int, string>(4, "Africa"),
		pair<int, string>(1, "Euro"),
		pair<int, string>(4, "America"),
	};
	//map中不能存放关键字相同的元素,
	//如果在添加时,关键字相同的元素会被过滤掉
	//默认情况下,map关的元素按升序排列
	//map中存放的是pair元素
	multimap<int, string, std::greater<int> > mapIntStr(arrPairs, arrPairs + 4);

	cout << "mapIntStr's size = " << mapIntStr.size() << endl;

	multimap<int,string>::iterator it;
	for(it = mapIntStr.begin();
		it != mapIntStr.end();
		++it)
	{
		cout << it->first << " ---> "
			 << it->second << endl;
	}
	return 0;
}
