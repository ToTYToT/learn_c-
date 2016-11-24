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
using std::string;
using std::pair;


int test(void)
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
	map<int, string, std::greater<int> > mapIntStr(arrPairs, arrPairs + 4);

	cout << "mapIntStr's size = " << mapIntStr.size() << endl;

	map<int,string>::iterator it;
	for(it = mapIntStr.begin();
		it != mapIntStr.end();
		++it)
	{
		cout << it->first << " ---> "
			 << it->second << endl;
	}
	cout << endl;

	//map的下标访问运算符中的参数代表的是关键字
	cout << mapIntStr[1] << endl;
	cout << mapIntStr[4] << endl;
	cout << mapIntStr[9] << endl;

	mapIntStr[4] = "America";
	cout << mapIntStr[4] << endl;
	return 0;
}

int main(void)
{
	test();
	pair<string, string> arrPairs[4] = {
		pair<string, string>("aa", "Asia"),
		pair<string, string>("bb", "Africa"),
		pair<string, string>("cc", "Euro"),
		pair<string, string>("dd", "America"),
	};
	//map中不能存放关键字相同的元素,
	//如果在添加时,关键字相同的元素会被过滤掉
	//默认情况下,map关的元素按升序排列
	//map中存放的是pair元素
	map<string, string, std::greater<string> > mapIntStr(arrPairs, arrPairs + 4);

	cout << "mapIntStr's size = " << mapIntStr.size() << endl;

	map<string,string>::iterator it;
	for(it = mapIntStr.begin();
		it != mapIntStr.end();
		++it)
	{
		cout << it->first << " ---> "
			 << it->second << endl;
	}
	cout << endl;

	//map的下标访问运算符中的参数代表的是关键字
	cout << mapIntStr["aa"] << endl;
	cout << mapIntStr["bb"] << endl;
	cout << mapIntStr["cc"] << endl;
	cout << mapIntStr["dd"] << endl;

	mapIntStr["dd"] = "Austrilia";
	cout << mapIntStr["dd"] << endl;
	return 0;
}
