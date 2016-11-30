 ///
 /// @file    PageLibPreprocessor.cc
 /// @author  ToTYToT(hongzimeng@foxmail.com)
 /// @date    2016-11-27 18:40:17
 ///
 
#include "_THE_INFO_OF_RUN.h"
#include "PageLibPreprocessor.h"
#include "WebPage.h"
#include "Configuration.h"
#include <cmath>
namespace T520
{

PageLibPreprocessor::PageLibPreprocessor(Configuration & conf)
:_conf(conf)
,_pageLib()
,_jieba()
,_offsetLib()
,_invertIndexTable()
,_docFreqMap()
,_docNum(0)
,_inverseDocFreqMap()
{
}

void PageLibPreprocessor::doProcess()
{
	readInfoFromFile();
	cutRedundantPages();
	createWeight();
	createOffsetLib();
	storeOnDisk();
}

void PageLibPreprocessor::readInfoFromFile()
{
	ifstream ifpage(_conf.getConfigMap()["ripepage.lib"].c_str());
	ifstream ifoffsize(_conf.getConfigMap()["offset.lib"].c_str());
	string line;
	while(getline(ifpage,line))
	{
		//WebPage pagetmp=new WebPage(line,_conf,_jieba);
		WebPage pagetmp(line,_conf,_jieba);
		_pageLib.push_back(pagetmp);
	}
}

void PageLibPreprocessor::cutRedundantPages()
{
	vector<WebPage>::iterator lit;
	vector<WebPage>::iterator rit;
	for(lit=_pageLib.begin();lit!=_pageLib.end();++lit)
	{
		for(rit=_pageLib.begin();rit!=_pageLib.end();++rit)
		{
			if(lit!=rit)
				if(*lit==*rit)
					_pageLib.erase(rit);
		}
	}
}

void PageLibPreprocessor::createDocfreqMap()
{
	vector<WebPage>::iterator vit;
	map<string,int> mtmp;
	map<string,int>::iterator mit;
	for(vit=_pageLib.begin();vit!=_pageLib.end();++vit)
	{
		++_docNum;
		mtmp=(*vit).getWordsMap();
		for(mit=mtmp.begin();mit!=mtmp.end();++mit)
			++(_docFreqMap[mit->first]);
	}
}

void PageLibPreprocessor::createIDF()
{
	createDocfreqMap();
	map<string,int>::iterator mit;
	for(mit=_docFreqMap.begin();mit!=_docFreqMap.end();++mit)
		_inverseDocFreqMap[mit->first]=log(_docNum/mit->second)/log(2);
}

void PageLibPreprocessor::createWeight()
{
	createIDF();
	vector<WebPage>::iterator vit;
	map<string,int>::iterator mit;
	map<string,double>::iterator wmit;
	map<string,int> mtmp;
	map<string,double> mwtmp;
	double weighttmp;
	int num;
	for(num=1,vit=_pageLib.begin();vit!=_pageLib.end();++vit,++num)
	{
		mtmp=(*vit).getWordsMap();
		mwtmp=(*vit).getWordsWeightMap();
		for(mit=mtmp.begin();mit!=mtmp.end();++mit)
		{
			mwtmp[mit->first]=(mit->second)*_inverseDocFreqMap[mit->first];
			weighttmp=(mwtmp[mit->first])*(mwtmp[mit->first]);
		}
		weighttmp=sqrt(weighttmp);
		for(wmit=mwtmp.begin();wmit!=mwtmp.end();++wmit)
		{
			wmit->second/=weighttmp;
			_invertIndexTable[wmit->first].push_back({num,wmit->second});
		}
	}
}

void PageLibPreprocessor::buildInvertIndexTable()
{
	createWeight();
}

void PageLibPreprocessor::createWeightAdvence()
{

}

void PageLibPreprocessor::createOffsetLib()
{
	ofstream ofpage(_conf.getConfigMap()["ripepage.lib"].c_str());
	ofstream ofoffsize(_conf.getConfigMap()["offset.lib"].c_str());
	vector<WebPage>::iterator vit;
	string tmp;
	int id;
	int offsize=0;
	for(vit=_pageLib.begin();vit!=_pageLib.end();++vit)
	{
		tmp=(*vit).getDoc();
		id=(*vit).getDocId();
		ofpage<<tmp;
		ofoffsize<<id<<" "<<offsize<<" "<<tmp.size()<<endl;
		_offsetLib[id]={offsize,tmp.size()};
		offsize+=tmp.size();
	}
}

void PageLibPreprocessor::storeOnDisk()
{
	ofstream ofInverse(_conf.getConfigMap()["invertindex.lib"].c_str());
	unordered_map<string,vector<pair<int,double> > >::iterator mit;
	vector<pair<int,double> >::iterator vit;
	for(mit=_invertIndexTable.begin();mit!=_invertIndexTable.end();++mit)
	{
		ofInverse<<mit->first<<" ";
		for(vit=(mit->second).begin();vit!=(mit->second).end();++vit)
			ofInverse<<vit->first<<" "<<vit->second;
		ofInverse<<endl;
	}
}

}
using namespace T520;
int main()
{

}
