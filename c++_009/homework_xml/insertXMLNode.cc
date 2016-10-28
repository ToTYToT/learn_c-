 ///
 /// @file    insertXMLNode.cc
 /// @author  ToTYToT(hongzimeng@foxmail.com)
 /// @date    2016-10-27 21:04:23
 ///
 
#include "tinyxml2.h"  
#include <stdlib.h>
#include <stdio.h>
#include <iostream>
#include <string>
#include <vector>
#include <sstream>
using std::cout;
using std::endl;
using std::string;
using std::vector;
using std::ostringstream;
using namespace tinyxml2;  

struct RssItem
{
	string title;
	string link;
	string description;
	string content;
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
	void parseRss(const char * xmlPath);//解析
	void insertNode(XMLElement* userNode,XMLDocument &doc,const char *name,const char* test);
	void dump(const char*xmlPath);//输出
private:
	RssData _rssData;
};  
RssReader::RssReader()
:_rssData()
{};
void RssReader::parseRss(const char * xmlPath)
{
	XMLDocument doc;
	if(doc.LoadFile(xmlPath)!=0)
	{
		cout<<"load xml file failed"<<endl;
		return ;
	}
	//XMLElement* root=doc.RootElement();
	//XMLElement* channelNode=root->FirstChildElement("channel");
    XMLElement * channelNode=doc.FirstChildElement("rss")->FirstChildElement("channel");
    //cout<<channelNode<<endl;
	RssData mynode;
	XMLElement * title=channelNode->FirstChildElement("title");
    //XMLElement * title=doc.FirstChildElement("rss")->FirstChildElement("channel")->FirstChildElement("title");
    cout<<title<<endl;
	mynode.title=title->GetText();
    #if 1
	XMLElement * date=channelNode->FirstChildElement("pubDate");
    cout<<date<<endl;
	mynode.date=date->GetText();
	XMLElement * description=channelNode->FirstChildElement("description");
    cout<<description<<endl;
	mynode.description=description->GetText();
	XMLElement * link=channelNode->FirstChildElement("link");
    cout<<link<<endl;
	mynode.link=link->GetText();
	XMLElement * item=channelNode->FirstChildElement("item");
    cout<<item<<endl;
	//XMLElement * content;
    cout<<"RssReader"<<endl;
	RssItem tmp_item;
	while(item!=NULL)
	{
//    cout<<"RssReader"<<endl;
		title=item->FirstChildElement("title");
		tmp_item.title=title->GetText();
		link=item->FirstChildElement("link");
		tmp_item.link=link->GetText();
		description=item->FirstChildElement("description");
        tmp_item.description=description->GetText();
		//content=item->FirstChildElement("content");
		//tmp_item.content=content->GetText();
  //  cout<<"RssReader"<<endl;
		mynode.items.push_back(tmp_item);
        _rssData=mynode;
		item=item->NextSiblingElement();
	}
#endif
}
#if 1
void RssReader::insertNode(XMLElement* userNode,XMLDocument &doc,const char *name,const char* test)
{
	XMLElement * docid;
	docid= doc.NewElement(name);
	docid->InsertEndChild(doc.NewText(test));	
	userNode->InsertEndChild(docid);
}
#endif
void RssReader::dump(const char * xmlPath)
{
    const char* declaration ="<?xml version=\"1.0\" encoding=\"UTF-8\" standalone=\"no\"?>";
    XMLDocument doc;
    doc.Parse(declaration);//会覆盖xml所有内容
    XMLElement* root=doc.NewElement("HELLO");
	doc.InsertEndChild(root);
    doc.SaveFile(xmlPath);
	int res=doc.LoadFile(xmlPath);
	if(res!=0)
	{
		cout<<"load xml file failed"<<endl;
		return;
	}
    XMLElement* userNode; 
	root->InsertEndChild(userNode);
	vector<RssItem>::iterator iter;
    cout<<_rssData.items.size()<<endl;
	int i=1;
    ostringstream ss;
    char buf[10]={0};
	for (iter=_rssData.items.begin();iter!=_rssData.items.end();++iter,++i)  
	{ 
		userNode = doc.NewElement("doc");
		root->InsertEndChild(userNode);
        #if 1
        ss.str(""); //the way can't write into the .dat
        ss<<i;
	    insertNode(userNode,doc,"docid",ss.str().c_str());
        #endif

        #if 0
        sprintf(buf,"%d",i);
        insertNode(userNode,doc,"docid",buf);

        #endif
        //insertNode(userNode,doc,"docid","1");
		insertNode(userNode,doc,"title",iter->title.c_str());
		insertNode(userNode,doc,"description",iter->description.c_str());
		insertNode(userNode,doc,"content",iter->content.c_str());
	}  
	doc.SaveFile(xmlPath);
	return;
}
int main()
{
	RssReader a;
	a.parseRss("36kr.xml");
	a.dump("36kr.dat");
	return 0;
}
