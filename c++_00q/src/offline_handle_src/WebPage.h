 ///
 /// @file    WebPage.h
 /// @author  ToTYToT(hongzimeng@foxmail.com)
 /// @date    2016-11-25 16:03:15
 ///
#ifndef __T__WEBPAGE_H__
#define __T__WEBPAGE_H__
#include "_THE_INFO_OF_RUN.h"
namespace T520
{
class WebPage
{
    const static int TOPK_NUMBER=20;
    friend bool operator==(const WebPage&lhs,const WebPage&rhs);
    friend bool operator<(const WebPage&lhs,const WebPage&rhs);
public:
    WebPage(string &doc, Configuration &config,WordSegmentation &jieba);
    int getDocId();
    string getDoc();
    //string getTitle();
    //string summary(const vector<string> &queryWords);
    map<string,int> &getWordsMap();
private:
    void processDoc(const string &doc,Configuration &config,WordSegmentation &jieba);
    void calcTopK(vector<string> &wordsVec,int k,set<string>&stopWordList);
private:
    string _doc;
    int _docId;
    string _docTitle;
    string _docUrl;
    string _docContent;
    string _docSummary;
    vector<string> _topWords;
    map<string,int> _wordsMap;
};
}
#endif
