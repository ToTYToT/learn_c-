 ///
 /// @file    AndQuery.h
 /// @author  lemon(haohb13@gmail.com)
 /// @date    2016-11-09 11:32:12
 ///
 
#ifndef __WANGDAO_AND_QUERY_H__
#define __WANGDAO_AND_QUERY_H__

#include "BinaryQuery.h"
#include <iostream>
using std::cout;
using std::endl;


class AndQuery
: public BinaryQuery
{
	//friend class Query;
	friend Query operator&(const Query & lhs, const Query & rhs);

	AndQuery(const Query & lhs, const Query & rhs)
	: BinaryQuery(lhs, rhs, "&")
	{}

	set<int> doQuery(const TextQuery & tq) const;
};


#endif
