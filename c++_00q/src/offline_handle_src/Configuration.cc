 ///
 /// @file    Configuration.cc
 /// @author  ToTYToT(hongzimeng@foxmail.com)
 /// @date    2016-11-27 11:23:36
 ///
#include "Configuration.h" 
namespace T520
{
Configuration::Configuration(const string&filepath)
:_filepath(filepath)//
,_confiMap()
,_stopWordList()
{
	_THE_INFO_OF_RUN;
	//1) ripepage.lib路径
	//2) offset.lib路径
	//3) invertindex.lib路径
	//4) 分词库路径
	//5) 停用词库路径
	//6) 服务器 IP, port
}
map<string,string> & Configuration::getConfigMap()
{
	_THE_INFO_OF_RUN;
    std::ifstream fint(_filepath);
    std::string line;
	std::string word;
	std::vector<std::string >wordVector;
    while(getline(fint,line))
    {
        std::istringstream iss(line);
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
	return _confiMap;
}
set<string> Configuration::getStopWordList()
{
	_THE_INFO_OF_RUN;
    std::ifstream fint(_confiMap["stopWordList.path"]);
    std::string line;
	std::string word;
    while(getline(fint,line))
    {
        std::istringstream iss(line);
        while(iss>>word)
			_stopWordList.insert(word);
    }
	return _stopWordList;
}
}
//using namespace T520;
//int main()
//{
//	Configuration conf("../../conf/myconf.conf");
//	conf.getConfigMap();
//	conf.getStopWordList();
//}
