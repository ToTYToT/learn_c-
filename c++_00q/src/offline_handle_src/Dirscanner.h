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
namespace T520
{
class Configuration;
class Dirscanner
{
public:
    Dirscanner(Configuration& conf);
	vector<string> getFiles();
private:
	void createFiles(const string&dirname);
private:
    vector<string> _vecFilesfiles;
    Configuration &_conf;
};
}
#endif
