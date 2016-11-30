 ///
 /// @file    WordQuery.cc
 /// @author  ToTYToT(hongzimeng@foxmail.com)
 /// @date    2016-11-29 17:09:42
 ///
 
#include "_THE_INFO_OF_RUN.h"
#include "WordQuery.h"
#include "jieBa.h"
#include "Configuration.h"
#include "WebPage.h"
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

string WordQuery::doQuery(const string & str)
{
	vector<string> queryWords;
	vector<pair<int,vector<double> > > resultVec;
	_jieba(str,queryWords);
	if(executeQuery(queryWords,resultVec))
	{
		vector<int> docIdVec;
		//map<int,double> docidmap;
		vector<pair<int,double> > docidweightvec;
		vector<pair<int,vector<double> > >::iterator vit;
		vector<double>::iterator weightvit;
		vector<double>::iterator queryweightvit;
		vector<double> queryWordsWeight;
		double x=y=z=0;
		queryWordsWeight=getQueryWordsWeightVector(queryWords);
		for(vit=resultVec.begin();vit!=resultVec.end();++vit)
		{
			for(weightvit=(vit->second).begin(),queryweightvit=queryWordsWeight.begin();weightvit!=(vit->second).end(),queryweightvit!=queryWordsWeight.end();++weightvit++queryweightvit)
			{
				x+=(*queryweightvit)*(*queryweightvit);
				z+=(*queryweightvit)*(*weightvit);
				y+=(*queryweightvit)*(*weightvit);
			}
		//	docidmap[vit->first]=z/(x*y);
			docidweightvec.push_back({vit->first,z/(x*y)});
			sort(docidweightvec.begin();docidweightvec.end();WordQuery::docidweithbyvaluecmp);
		}
		//map<int,double>::iterator tmpmapit;
		vector<pair<int,double> > ::iterator tmpvecit;
		for(tmpvecit=docidweightvec.begin();tmpvecit!=docidweightvec.end();++tmpmapit)
			docIdVec.push_back(tmpmapit->first);
		return createJson(docIdVec,queryWords);
	}
	else
		return returnNoAnswer();
}

bool WordQuery::docidweithbyvaluecmp(const pair<int,double>&lth,const pair<int,double> &rth)
{
	return lth.second>rth.second;
}

bool WordQuery::executeQuery(const vector<string> & queryWords,vector<pair<int,vector<double> > > & resultVec)
{
	vector<string>::iterator findVit;
	for(findVit=queryWords.begin();findVit!=queryWords.end();++findVit)
	{
		auto findMit=_invertIndexTable(*findVit);
		if(findMit==_invertIndexTable.end())
			return false;
	}
	auto mapFind=unordered_map.find(queryWords[0]);
	vector<pair<int,double> >::iterator docidvit;
	vector<double> docWeight;
	for(docidvit=(mapFind->second).begin();docidvit!=(mapFind->second).end();++docidvit)
	{
		docidvit.erase(docidvit.begin(),docidvit.end());
		if(findWordWeight(queryWords,docidvit.first,docWeight))
		{
			resultVec.push_back({docidvit.first,docWeight});
		}
	}
}

vector<double> WordQuery::getQueryWordsWeightVector(vector<string> & queryWords)
{
	vector<double> queryWordsWeight;
//	vector<double>::iterator queryWordsit;
	vector<string>::iterator vit;
	map<string,int> mtmp;
	map<string,int>::iterator mit;
	for(vit=queryWords.begin();vit!=queryWordsWeight.end();++vit)
	{
		++mtmp[*vit];
	}
	double weightSum;
	for(mit=mtmp.begin();mit!=mtmp.end();++mit)
	{
		weightSum+=(mit->second)*(mit->second);
	}
	weightSum=-sqrt(weightSum);
	for(mit=mtmp.begin();mit!=mtmp.end();++mit)
	{
		queryWordsWeight.push_back(mit->second/weightSum);
	}
	return queryWordsWeight;
}

bool WordQuery::findWordWeight(vector<string> queryWords ,int docId,vector<double>&docWeight)
{
	vector<string>::iterator vit;
	vector<pair<int,double> > vvit;
	char flag='0';
	for(vit=queryWords.begin();vit!=queryWords.end();++vit)
	{
		flag='0';
		auto mret=_invertIndexTable.find(*vit);
		for(vvit=(mret->second).begin();vvit!=(mret->second).end();++vvit)
		{
			if(vvit->first==docId)
			{
				docWeight.push_back(vvit->second);
				flag='1';
				break;
			}
		}
		if(flag!='1')
		{
			return false;
		}
	}
	return true;
}

string WordQuery::createJson(vector<int> & docIdVec, const vector<string> & queryWords)
{
	return "It's here";
}

string WordQuery::returnNoAnswer()
{
	return "sorry,it's not here";
}


void WordQuery::loadLibrary()
{
    ifstream ifoffsize(_conf.getConfigMap()["offsize.lib"]);
    ifstream ifpage(_conf.getConfigMap()["ripepage.lib"]);
    ifstream ifinvertindex(_conf.getConfigMap()["invertindex.lib"]);
    string line;
    istringstream iss;
    int a,b,c;
    while(getline(ifoffsize,line))
    {
        iss.str("");
        iss.str(line);
        iss>>a>>b>>c;
        (_offsetLib[a])={b,c};
    }
    while(getline(ifpage,line))
    {
        WebPage a(line,_jieba,_conf);
        _pageLib[a.getDocId()]=a;
    }
    string s;
    double d;
    while(getline(ifinvertindex,line))
    {
        iss.str("");
        iss.str(line);
        iss>>s>>a>>d;
        _invertIndexTable[s].push_back({a,d});
    }
}

}
using namespace T520;
int main()
{
}
