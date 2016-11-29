 ///
 /// @file    readXML.cc
 /// @author  ToTYToT(hongzimeng@foxmail.com)
 /// @date    2016-10-27 21:04:23
 ///
#include "ReadXMLFile.h" 
namespace T520
{
ReadXMLFile::ReadXMLFile()
:_rssData()
,_item(NULL)
{};
void ReadXMLFile::parseRss(const char * xmlPath)
{
	_THE_INFO_OF_RUN;
	XMLDocument doc;
	if(doc.LoadFile(xmlPath)!=0)
	{
		cout<<"load xml file failed"<<endl;
		return ;
	}
    XMLElement * rssNode=doc.FirstChildElement("rss");
	if((NULL==rssNode)!=0)
	{
		return ;
	}
	XMLElement * channelNode=rssNode->FirstChildElement("channel");
    if(NULL==channelNode)
        return ;
	_item=channelNode->FirstChildElement("item");
	RssItem tmp_item;
	string itemtextstring;
	while(_item!=NULL)
	{
		tmp_item.title=getText("title");
        tmp_item.link=getText("link");
        tmp_item.content=getText("description");
        replaceContent(tmp_item.content);
		_rssData.push_back(tmp_item);
		_item=_item->NextSiblingElement();
	}
}
string ReadXMLFile::getText(string node)
{
    if(_item!=NULL)
    {
        XMLElement *nodeName=_item->FirstChildElement(node.c_str()); 
        if(nodeName!=NULL)
        {
            return nodeName->GetText();
        }else
        {
            return "";
        }
    }
}
void ReadXMLFile::replaceContent(string & content)
{
    boost::regex re1("<.*?>");
    boost::regex re2("&.*?;");
    content=boost::regex_replace(content, re1, string(""));
    content=boost::regex_replace(content, re2, string(""));
}
vector<RssItem> ReadXMLFile::getReadXMLtext()
{
	return _rssData;
}
}
//int main(){}
