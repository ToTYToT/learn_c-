 ///
 /// @file    PageLibPreprocessor.h
 /// @author  ToTYToT(hongzimeng@foxmail.com)
 /// @date    2016-11-25 15:52:03
 ///
#ifndef __T_PAGELIBPREPROCESSOR_H__ 
#define __T_PAGELIBPREPROCESSOR_H__ 
#include "_THE_INFO_OF_RUN.h"
#include "jieBa.h"
namespace T520
{
class WebPage;
class jieBa;
class Configuration;
class PageLibPreprocessor
{
public:
    PageLibPreprocessor(Configuration& conf);
    void doProcess();
private:
    void readInfoFromFile();
    void cutRedundantPages();//去重
    void buildInvertIndexTable();//倒排序表
    void storeOnDisk();//
	void createDocfreqMap();
	void createIDF();
	void createWeight();
	void createWeightAdvence();
	void createOffsetLib();
private:
    Configuration & _conf;
    //WordSegmentation _jieba;
	jieBa _jieba;
    vector<WebPage> _pageLib;
	map<string,int> _docFreqMap;
	map<string,double> _inverseDocFreqMap;
	int _docNum;
    unordered_map<int,pair<int,int> >  _offsetLib;
    unordered_map<string,vector<pair<int,double> > > _invertIndexTable;
};
}
#endif
