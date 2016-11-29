 ///
 /// @file    WordQuery.cc
 /// @author  ToTYToT(hongzimeng@foxmail.com)
 /// @date    2016-11-29 17:09:42
 ///
 
#include "_THE_INFO_OF_RUN.h"
#include "WordQuery.h"
namespace T520
{

WordQuery::WordQuery(Configuration & conf)
:_conf(conf)
,_jieba()
,_pageLib()
,_offsetLib()
,_invertIndexTable()
{

}

string doQuery()
{

}		

void WordQuery::loadLibrary()
{

}

vector<double> WordQuery::getQueryWordsWeightVector(vector<string> & queryWords)
{

}

bool WordQuery::executeQuery(const vector<string> & queryWords,vector<pair<int,vector<double> > > & resultVec)
{

}

string WordQuery::createJson(vector<int> & docIdVec, const vector<string> & queryWords)
{

}

string WordQuery::returnNoAnswer()
{

}

}
