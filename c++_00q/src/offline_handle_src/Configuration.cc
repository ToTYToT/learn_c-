 ///
 /// @file    Configuration.cc
 /// @author  ToTYToT(hongzimeng@foxmail.com)
 /// @date    2016-11-27 11:23:36
 ///
#include "Configuration.h" 
namespace T520
{
Configuration::Configuration(const string&filepath)
:_filepath(filepath)
,_confiMap()
,_stopWordList()
{
	_THE_INFO_OF_RUN;
	createConfigMap();
	createStopWordList();
}
map<string,string> & Configuration::getConfigMap()
{
	_THE_INFO_OF_RUN;
	return _confiMap;
}
void Configuration::createConfigMap()
{
	_THE_INFO_OF_RUN;
    ifstream fint(_filepath);
    string line;
	string word;
	vector<string >wordVector;
    while(getline(fint,line))
    {
        istringstream iss(line);
        while(iss>>word)
			wordVector.push_back(word);
    }
	_confiMap["ripepage.lib"]=wordVector[0];
	_confiMap["offset.lib"]=wordVector[1];
	_confiMap["invertindex.lib"]=wordVector[2];
	_confiMap["jieba.path"]=wordVector[3];
	_confiMap["stopWordList.path"]=wordVector[4];
	_confiMap["dataSource.path"]=wordVector[5];
	_confiMap["ip"]=wordVector[6];
	_confiMap["port"]=wordVector[7];
}
set<string> Configuration::getStopWordList()
{
	_THE_INFO_OF_RUN;
	return _stopWordList;
}
void Configuration::createStopWordList()
{
	_THE_INFO_OF_RUN;
    ifstream fint(_confiMap["stopWordList.path"]);
    string line;
	string word;
    while(getline(fint,line))
    {
        istringstream iss(line);
        while(iss>>word)
			_stopWordList.insert(word);
    }
}
}
//using namespace T520;
//int main()
//{
//	Configuration conf("../../conf/myconf.conf");
//	conf.getConfigMap();
//	conf.getStopWordList();
//}
