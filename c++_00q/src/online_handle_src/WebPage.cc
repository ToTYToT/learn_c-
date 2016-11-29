 ///
 /// @file    WebPage.cc
 /// @author  ToTYToT(hongzimeng@foxmail.com)
 /// @date    2016-11-27 18:40:46
 ///
 
#include "_THE_INFO_OF_RUN.h"
#include "WebPage.h"
namespace T520
{

WebPage::WebPage(string &doc,Configuration &config,jieBa &jieba)
:_doc(doc)
,_conf(config)
,_jieba(jieba)
,_topWords()
,_allWords()
,_wordsMap()
,_wordsWeightMap()
{
	_THE_INFO_OF_RUN;
}

int WebPage::getDocId()
{
	_THE_INFO_OF_RUN;
	return _docId;
}

int WebPage::getDocId() const
{
	_THE_INFO_OF_RUN;
	return _docId;
}

string &WebPage::getDoc()
{
	_THE_INFO_OF_RUN;
	return _doc;
}
string WebPage::getTitle()
{
	_THE_INFO_OF_RUN;
	return _docTitle;
}

string WebPage::summary(const vector<string>&queryWords)
{
	_THE_INFO_OF_RUN;

}

map<string,int>& WebPage::getWordsMap()
{
	return _wordsMap;
}

map<string,double>& WebPage::getWordsWeightMap()
{
	return _wordsWeightMap;
}
vector<string> & WebPage::getTopwords() 
{
	return _topWords;
}

vector<string>  WebPage::getTopwords() const
{
	return _topWords;
}

void WebPage::processDoc(const string &doc)
{
	_THE_INFO_OF_RUN;
	_docId=atoi(getString("<docid>","</docid>",doc).c_str());
	_docUrl=getString("<url>","</url>",doc);
	_docTitle=getString("<title>","</title>",doc);
	_docContent=getString("<content>","</content>",doc);
	_jieba.jieBaVector(_docContent,_allWords);
}

string WebPage::getString(string itemBegin,string itemEnd,string doc)
{
	_THE_INFO_OF_RUN;
	string::size_type beginPos;
	string::size_type endPos;
	beginPos=doc.find(itemBegin.c_str())+itemBegin.size();
	endPos=doc.find(itemEnd.c_str());
	return doc.substr(beginPos,endPos-beginPos);
}

//void clacTopK(vector<string> &wordsVec,int k,set<string>&stopWordList)
void WebPage::calcTopK(set<string>&stopWordList)
{
	char flag='1';
	for(auto & elem : _allWords)
	{
		flag='1';
		for(auto & stopword : stopWordList)
			if(elem==stopword)
			{
				flag='0';
				break;
			}
		if(flag)
			++_wordsMap[elem];
	}
	for(auto & elem : _wordsMap)
		cout<<elem.second<<endl;
	map<int,vector<string> > it;
	map<string,int>::iterator mit;
	for(mit=_wordsMap.begin();mit!=_wordsMap.end();++mit)
		it[mit->second].push_back(mit->first);
	map<int,vector<string> >::iterator mmit;
	mmit=it.begin();
	vector<string>::iterator vit;
	for(int num=0;mmit!=it.end()&&num!=TOPK_NUMBER;++mmit)
	{
		for(vit=(mmit->second).begin();vit!=(mmit->second).end()&&num!=TOPK_NUMBER;++vit,++num)
		{
			_topWords.push_back(*vit);
		}
	}
}

#if 1
bool operator==(const WebPage&lhs, const WebPage&rhs)
{
	_THE_INFO_OF_RUN;
	//lhs.getTitle();
	vector<string>::iterator lvit;
	vector<string>::iterator rvit;
	//vector<string> ltmp=WebPage::lhs.getTopwords();
	//vector<string> rtmp=rhs.getTopwords();
	vector<string> ltmp(lhs.getTopwords());
	vector<string> rtmp(rhs.getTopwords());
	int num=0;
	for(lvit=ltmp.begin();lvit!=ltmp.end()&&num!=16;++lvit)
	{
		for(rvit=rtmp.begin();rvit!=rtmp.end();++rvit)
		{
			if(0==(*lvit).compare(*rvit))
			{
				++num;
				break;
			}
		}
	}
	if(num==16)
		return true;
	else
		return false;
}
#endif

bool operator<(const WebPage&lhs, const WebPage&rhs)
{
	if(lhs.getDocId()<rhs.getDocId())
		return true;
	else
		return false;
}

}

//using namespace T520;
//int main()
//{
//	jieBa a;
//	Configuration b("../../conf/myconf.conf");
//	string c("hello world");
//	WebPage d(c,b,a);
//	d.getWordsMap();
//}
