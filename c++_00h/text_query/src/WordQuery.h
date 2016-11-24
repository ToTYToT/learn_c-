 ///
 /// @file    WordQuery.h
 /// @author  lemon(haohb13@gmail.com)
 /// @date    2016-11-09 11:17:17
 ///
 
#ifndef __WANGDAO_WORDQUERY_H__
#define __WANGDAO_WORDQUERY_H__


#include "Base.h"
#include <string>
using std::string;

class TextQuery;

class WordQuery
: public Base{
	friend class Query;

	WordQuery(const string & rhs);

	virtual
	set<int> doQuery(const TextQuery & tq) const;

	virtual
	std::ostream & display(std::ostream & os) const;
private:
	string _queryWord;
};

#endif
