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

	void parseRss();//解析
	void dump();//输出
private:
RssData _rssData;
};

int createXML(const char* xmlPath)
{
	const char* declaration ="<?xml version=\"1.0\" encoding=\"UTF-8\" standalone=\"no\"?>";
	XMLDocument doc;
	doc.Parse(declaration);//会覆盖xml所有内容
	//添加申明可以使用如下两行
	//XMLDeclaration* declaration=doc.NewDeclaration();
	//doc.InsertFirstChild(declaration);
	XMLElement* root=doc.NewElement("DBUSER");
	doc.InsertEndChild(root);
	return doc.SaveFile(xmlPath);
}

int insertXMLNode(const char* xmlPath,const User& user)
{
XMLDocument doc;
int res=doc.LoadFile(xmlPath);
if(res!=0)
{
cout<<"load xml file failed"<<endl;
return res;
}
XMLElement* root=doc.RootElement();

XMLElement* userNode = doc.NewElement("docid");
//userNode->SetAttribute("Name",user.userName.c_str());
root->InsertEndChild(userNode);
XMLElement* gender = doc.NewElement("Gender");
XMLText* genderText=doc.NewText(itoa(user.gender));
gender->InsertEndChild(genderText);
userNode->InsertEndChild(gender);
XMLElement* mobile = doc.NewElement("Mobile");
mobile->InsertEndChild(doc.NewText(user.mobile.c_str()));
userNode->InsertEndChild(mobile);
XMLElement* email = doc.NewElement("Email");
email->InsertEndChild(doc.NewText(user.email.c_str()));
userNode->InsertEndChild(email);
return doc.SaveFile(xmlPath);
}
