 ///
 /// @file    ReadXMLFile.h
 /// @author  ToTYToT(hongzimeng@foxmail.com)
 /// @date    2016-11-26 16:10:56
 ///
#ifndef __T_READXMLFILE_H__
#define __T_READXMLFILE_H__
#include "_THE_INFO_OF_RUN.h"
#include <boost/regex.hpp>
#include "tinyxml2.h"  
#include <stdlib.h>
#include <stdio.h>
#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <fstream>
#include <map>
#include <utility>
#include <unordered_map>
using std::cout;
using std::endl;
using std::string;
using std::vector;
using std::ostringstream;
using std::ofstream;
using std::map;
using std::unordered_map;
using std::pair;
using namespace tinyxml2;  
namespace T520
{
struct RssItem
{
	string title;
	string link;
	string content;
};
class ReadXMLFile
{
public:
	ReadXMLFile();
	void parseRss(const char * xmlPath);
	vector<RssItem> getReadXMLtext();
private:
	string getText(string node);
	void replaceContent(string & content);
private:
	vector<RssItem> _rssData;
	XMLElement *_item;
};  
}
#endif
