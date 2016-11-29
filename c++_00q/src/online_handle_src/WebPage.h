 ///
 /// @file    WebPage.h
 /// @author  ToTYToT(hongzimeng@foxmail.com)
 /// @date    2016-11-25 16:03:15
 ///
#ifndef __T__WEBPAGE_H__
#define __T__WEBPAGE_H__
#include "_THE_INFO_OF_RUN.h"
#include "jieBa.h"
#include "Configuration.h"
namespace T520
{
class Configuration;
class jieBa;
class WebPage
{
    const static int TOPK_NUMBER=20;
    friend bool operator==(const WebPage&lhs,const WebPage&rhs);
    friend bool operator<(const WebPage&lhs,const WebPage&rhs);
public:
    //WebPage(string &doc, Configuration &config,WordSegmentation &jieba);
    WebPage(string &doc, Configuration &config,jieBa &jieba);
    int getDocId();
    int getDocId() const;
    string &getDoc();
    string getTitle();
    string summary(const vector<string> &queryWords);
    map<string,int> &getWordsMap();
	map<string,double>&getWordsWeightMap();
	//vector<string> & getTopwords();
	vector<string>  getTopwords() const;
	vector<string> & getTopwords();
private:
    //void processDoc(const string &doc,Configuration &config,WordSegmentation &jieba);
    void processDoc(const string &doc);
	//void calcTopK(vector<string> &wordsVec,int k,set<string>&stopWordList);
    void calcTopK(set<string>&stopWordList);
	string getString(string itemBegin,string itemEnd,string doc);
private:
    string _doc;
    int _docId;
    string _docTitle;
    string _docUrl;
    string _docContent;
    string _docSummary;
    vector<string> _topWords;
	vector<string> _allWords;
    map<string,int> _wordsMap;
    map<string,double> _wordsWeightMap;
	Configuration _conf;
	//WordSegmentation _jieba;
	jieBa _jieba;
};
}
#endif
