 ///
 /// @file    TextQuery.cc
 /// @author  lemon(haohb13@gmail.com)
 /// @date    2016-11-09 10:25:09
 ///
 
#include "TextQuery.h"
#include <iostream>
#include <fstream>
#include <sstream>

using std::cout;
using std::endl;
using std::ifstream;
using std::istringstream;


void TextQuery::readFile(const string & filename){
	ifstream ifs(filename);
	if(!ifs.good()){
		cout << "ifstream open error!" << endl;
		return;
	}
	
	string line;
	while(getline(ifs, line)){
		_lines.push_back(line);
		int no = _lines.size() - 1;
		string word;
		istringstream iss(line);
		while(iss >> word){
			_wordMap[word].insert(no);
		}
	}
}

set<int> TextQuery::doQuery(const string & word) const{
	auto iter = _wordMap.find(word);
	if(iter != _wordMap.end()){
		return iter->second;
	}else{
		return set<int>();
	}
}


string TextQuery::getLine(int number) const{
	return _lines[number];
}

int TextQuery::size() const{
	return _lines.size();
}

