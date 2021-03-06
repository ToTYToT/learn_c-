 ///
 /// @file    WordQuery.h
 /// @author  ToTYToT(hongzimeng@foxmail.com)
 /// @date    2016-11-25 16:18:21
 ///
#ifndef __T_WORDQUERY_H__
#define __T_WORDQUERY_H__
#include "_THE_INFO_OF_RUN.h"
#include "jieBa.h"
#include "WebPage.h"
namespace T520
{
class jieBa;
class Configuration;
class WebPage;
class WordQuery
{
public:
    WordQuery(Configuration & conf);
    string doQuery(const string & str);
private:
    void loadLibrary();
    vector<double> getQueryWordsWeightVector(vector<string> & queryWords);
    bool executeQuery(const vector<string> &queryWords,vector<pair<int,vector<double> > > &resultVec);
	bool findWordWeight(vector<string> queryWords ,int docId,vector<double>&docWeight)
    string createJson(vector<int> & docIdVec,const vector<string> & queryWords);
	bool docidweithbyvaluecmp(const pair<int,double>&lth,const pair<int,double> &rth)
    string returnNoAnswer();
private:
    Configuration & _conf;
    //WordSegmentation _jieba;
	jieBa _jieba;
    unordered_map<int, WebPage> _pageLib;
    unordered_map<int,pair<int,int> > _offsetLib;
    //unordered_map<string, set<pair<int,double> > _invertIndexTable;
    unordered_map<string, vector<pair<int,double> > > _invertIndexTable;
};
}
#endif
