 ///
 /// @file    Query.cc
 /// @author  lemon(haohb13@gmail.com)
 /// @date    2016-11-09 11:07:23
 ///
 
#include "Query.h"

#include "WordQuery.h"
#include "NotQuery.h"
#include "OrQuery.h"
#include "AndQuery.h"
#include "TextQuery.h"

#include <iostream>
using std::cout;
using std::endl;


Query::Query(const string & word)
: _basePtr(new WordQuery(word))
{
}

Query::Query(Base * pBase)
: _basePtr(pBase)
{}
	
set<int> Query::doQuery(const TextQuery & tq)const
{
	return	_basePtr->doQuery(tq);
}

std::ostream & Query::display(std::ostream & os) const
{
	return _basePtr->display(os);
}


Query operator~(const Query & lhs)
{
	//调用Query(Base *) ,有一个隐式转换
	return new NotQuery(lhs);
}

Query operator|(const Query & lhs, const Query & rhs)
{
	return new OrQuery(lhs, rhs);
}


Query operator&(const Query & lhs, const Query & rhs)
{
	return new AndQuery(lhs, rhs);
}

std::ostream & operator<<(std::ostream & os, const Query & rhs)
{
	rhs.display(os);
	return os;
}

void showResult(const TextQuery & tq, const set<int> & numbers)
{
	cout << "Query results:" << endl;
	for(auto it = numbers.begin();
		it != numbers.end();
		++it)
	{
		 cout << "    (" << (*it) + 1 << ") "
			  << tq.getLine(*it) << endl;
	}
}
