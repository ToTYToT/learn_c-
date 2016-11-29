 ///
 /// @file    PageLib.cc
 /// @author  ToTYToT(hongzimeng@foxmail.com)
 /// @date    2016-11-25 15:41:25
 ///
#ifndef __T_PAGELIB_H__ 
#define __T_PAGELIB_H__
#include "_THE_INFO_OF_RUN.h"
namespace T520
{
class Configuration;
class Dirscanner;
class ReadXMLFile;
struct RssItem;
class PageLib
{
public:
    PageLib(Configuration &conf,Dirscanner &dirscanner,ReadXMLFile& readXML);
    void create();
    void store();
private:
    Configuration &_conf;
    Dirscanner &_dirScanner;
	ReadXMLFile&_readXML;
    vector<string> _vecFilesfiles;
    map<int, pair<int,int> > _offsetLib;
	unsigned _docId;
};
}
#endif
