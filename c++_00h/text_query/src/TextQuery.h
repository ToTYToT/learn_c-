 ///
 /// @file    TextQuery.h
 /// @author  lemon(haohb13@gmail.com)
 /// @date    2016-11-09 10:18:19
 ///
 
#ifndef __WANGDAO_TEXTQUERY_H__
#define __WANGDAO_TEXTQUERY_H__
 
#include <vector>
#include <map>
#include <set>
#include <string>
using std::vector;
using std::map;
using std::set;
using std::string;

class TextQuery{
public:
	void readFile(const string & filename);
	set<int> doQuery(const string & word) const;
	string getLine(int number) const;
	int size() const;

private:
	vector<string> _lines;
	map<string, set<int> > _wordMap;
};

#endif
