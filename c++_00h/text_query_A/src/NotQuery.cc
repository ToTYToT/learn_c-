 ///
 /// @file    NotQuery.cc
 /// @author  lemon(haohb13@gmail.com)
 /// @date    2016-11-09 15:32:30
 ///
 
#include "NotQuery.h"
#include <iostream>
using std::cout;
using std::endl;


NotQuery::NotQuery(const Query & query)
: _query(query)
{}


set<int> NotQuery::doQuery(const TextQuery & tq) const
{
	set<int> ret;
	set<int> foundNums = _query.doQuery(tq);
	for(int idx = 0; idx != tq.size(); ++idx)
	{
		if(foundNums.find(idx) == foundNums.end()){
			ret.insert(idx);
		}
	}
	return ret;
}
	
std::ostream & NotQuery::display(std::ostream & os) const
{
	return os << "~(" << _query << ")";
}
