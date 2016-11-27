 ///
 /// @file    Dirscanner.h
 /// @author  ToTYToT(hongzimeng@foxmail.com)
 /// @date    2016-11-25 15:49:02
 ///
#ifndef __T_DIRSCANNER_H__ 
#define __T_DIRSCANNER_H__
#include "_THE_INFO_OF_RUN.h"
#include <sys/types.h>
#include <dirent.h>
#include <string.h>
#include <vector>
#include <string>
using std::string;
using std::vector;
namespace T520
{
class Configuration;
class Dirscanner
{
public:
    Dirscanner(Configuration& conf);
    void operator()();
    vector<string> files();
private:
    void traverse(const string& dirname);
private:
    vector<string> _vecFilesfiles;
    Configuration &_conf;
};
}
#endif
