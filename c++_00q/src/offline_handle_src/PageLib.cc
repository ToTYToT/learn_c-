 ///
 /// @file    PageLib.cc
 /// @author  ToTYToT(hongzimeng@foxmail.com)
 /// @date    2016-11-27 13:51:49
 ///
 
#include "_THE_INFO_OF_RUN.h"
#include "PageLib.h"
#include "Configuration.h"
#include "Dirscanner.h"
#include "ReadXMLFile.h"
namespace T520
{
PageLib::PageLib(Configuration &conf,Dirscanner &dirscanner,ReadXMLFile&readXML)
:_conf(conf)
,_dirScanner(dirscanner)
,_readXML(readXML)
,_docId(0)
,_vecFilesfiles()
,_offsetLib()
{
	_THE_INFO_OF_RUN;
}
void PageLib::create()
{
	_THE_INFO_OF_RUN;
	vector<string> tmp(_dirScanner.files());
	for(auto &elem : tmp)
		_readXML.parseRss(elem.c_str());
	vector<RssItem> itemTest(_readXML.getReadXMLtext());
	std::ostringstream sout;
	for(auto &elem : itemTest)
	{
		sout.str("");
		sout<<"<doc>"<<"<docid>"<<++_docId<<"</docid><url>"<<elem.link<<"</url><title>"<<elem.title<<"</title><content>"<<elem.content<<"</content></doc>"<<std::endl;
		_vecFilesfiles.push_back(sout.str());
	}
}
void PageLib::store()
{
	ofstream foutFiles(_conf.getConfigMap()["ripepage.lib"]);
	ofstream foutOffset(_conf.getConfigMap()["offset.lib"]);
	unsigned tmpid=0;
	unsigned tmpSize=0;
	for(auto &elem : _vecFilesfiles)
	{
		++tmpid;
		foutFiles<<elem;
		foutOffset<<tmpid<<" "<<tmpSize<<" "<<elem.size()<<"\n";
		tmpSize+=elem.size();
	}
}
}
using namespace T520;
int main(){}
