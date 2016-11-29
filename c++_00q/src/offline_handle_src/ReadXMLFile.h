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
