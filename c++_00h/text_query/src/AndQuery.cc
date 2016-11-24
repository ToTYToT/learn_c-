 ///
 /// @file    AndQuery.cc
 /// @author  lemon(haohb13@gmail.com)
 /// @date    2016-11-09 11:36:18
 ///
 
#include "AndQuery.h"
#include "TextQuery.h"
#include <iostream>
#include <algorithm>
#include <iterator>
using std::cout;
using std::endl;
	

set<int> AndQuery::doQuery(const TextQuery & tq) const
{
	set<int> left = _lhs.doQuery(tq);
	set<int> right = _rhs.doQuery(tq);
	set<int> _ret;

	std::set_intersection(left.begin(),	left.end(),
						  right.begin(), right.end(),
						  std::inserter(_ret, _ret.begin()));
	return _ret;
}
