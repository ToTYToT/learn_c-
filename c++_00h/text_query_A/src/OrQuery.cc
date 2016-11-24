 ///
 /// @file    OrQuery.cc
 /// @author  lemon(haohb13@gmail.com)
 /// @date    2016-11-09 11:36:18
 ///
 
#include "OrQuery.h"
#include "TextQuery.h"
#include <iostream>
#include <algorithm>
#include <iterator>
using std::cout;
using std::endl;
	

set<int> OrQuery::doQuery(const TextQuery & tq) const
{
	set<int> left = _lhs.doQuery(tq);
	set<int> right = _rhs.doQuery(tq);
	left.insert(right.begin(), right.end());
	return left;
}
