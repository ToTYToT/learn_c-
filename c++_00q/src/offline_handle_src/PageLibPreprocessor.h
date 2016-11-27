 ///
 /// @file    PageLibPreprocessor.h
 /// @author  ToTYToT(hongzimeng@foxmail.com)
 /// @date    2016-11-25 15:52:03
 ///
#ifndef __T_PAGELIBPREPROCESSOR_H__ 
#define __T_PAGELIBPREPROCESSOR_H__ 
#include "_THE_INFO_OF_RUN.h"
namespace T520
{
class PageLibPreprocessor
{
public:
    PageLibPreprocessor(Configuration& conf);
    void doProcess();
private:
    void readInfoFromFile();
    void cutRedundantPages();
    void buildInvertIndexTable();
    void storeOnDisk();
private:
    Configuration & _conf;
    WordSegmentation _jieba;
    vector<WebPage> _pageLib;
    unordered_map<int,pair<int,int> > _offsetLib;
    unordered_map<string,vector<pair<int,double> > _invertIndexTable;
};
}
#endif
