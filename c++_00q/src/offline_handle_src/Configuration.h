 ///
 /// @file    Configuration.h
 /// @author  ToTYToT(hongzimeng@foxmail.com)
 /// @date    2016-11-25 15:45:48
 ///
#ifndef __T_CONFIGURATION_H__
#define __T_CONFIGURATION_H__
#include "_THE_INFO_OF_RUN.h"
namespace T520
{
class Configuration
{
public:
    Configuration(const string&filepath);
    map<string,string> & getConfigMap();
    set<string> getStopWordList();
private:
	void createConfigMap();
	void createStopWordList();
private:
    string _filepath;
    map<string,string> _confiMap;
    set<string> _stopWordList;
};
}
#endif
