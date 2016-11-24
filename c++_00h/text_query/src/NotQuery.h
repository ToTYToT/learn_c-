 ///
 /// @file    NotQuery.h
 /// @author  lemon(haohb13@gmail.com)
 /// @date    2016-11-09 15:25:57
 ///
 
#ifndef __WANGDAO_NOT_QUERY_H__
#define __WANGDAO_NOT_QUERY_H__

#include "Base.h"
#include "Query.h"
#include <iostream>

using std::cout;
using std::endl;


class NotQuery 
: public Base
{
	friend class Query;
	friend Query operator~(const Query & lhs);

	NotQuery(const Query & query);
	set<int> doQuery(const TextQuery & tq) const;
	
	std::ostream & display(std::ostream & os) const;

private:
	Query _query;
};


#endif
