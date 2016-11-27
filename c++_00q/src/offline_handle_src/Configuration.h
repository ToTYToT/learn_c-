 ///
 /// @file    Configuration.h
 /// @author  ToTYToT(hongzimeng@foxmail.com)
 /// @date    2016-11-25 15:45:48
 ///
#ifndef __T_CONFIGURATION_H__
#define __T_CONFIGURATION_H__
#include "_THE_INFO_OF_RUN.h"
#include <fstream>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <set>
#include <map>
using std::map;
using std::string;
using std::set;
using std::vector;
namespace T520
{
class Configuration
{
public:
    Configuration(const string&filepath);
    map<string,string> & getConfigMap();
    set<string> getStopWordList();
private:
    string _filepath;
    map<string,string> _confiMap;
    set<string> _stopWordList;
};
}
#endif
