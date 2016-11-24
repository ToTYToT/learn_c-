 ///
 /// @file    WordQuery.cc
 /// @author  lemon(haohb13@gmail.com)
 /// @date    2016-11-09 11:20:28
 ///
 
#include "WordQuery.h"

#include "TextQuery.h"
#include <iostream>
using std::cout;
using std::endl;

WordQuery::WordQuery(const string & word)
: _queryWord(word)
{
}

set<int> WordQuery::doQuery(const TextQuery & tq) const{
	return tq.doQuery(_queryWord);
}

std::ostream & WordQuery::display(std::ostream & os) const
{
	return os << _queryWord;	
}
