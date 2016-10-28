 ///
 /// @file    homework.cc
 /// @author  ToTYToT(hongzimeng@foxmail.com)
 /// @date    2016-10-27 19:54:21
 ///

#include "tinyxml2.h"

#include <iostream>
#include <string>
#include <vector>
using std::cout;
using std::endl;
using std::string;
using std::vector;
using namespace tinyxml2;
struct RssItem
{
	string title="";
	string link="";
	string description="";
	string content="";
};
struct RssData
{
	string title;
	string link;
	string description;
	string date;
	vector<RssItem> items;
};   

class RssReader
{
public:
	RssReader();

	void parseRss();//解析
	void dump();//输出
private:
RssData _rssData;
};
