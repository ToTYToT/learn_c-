 ///
 /// @file    BinaryQuery.h
 /// @author  lemon(haohb13@gmail.com)
 /// @date    2016-11-09 11:27:17
 ///
 
#ifndef __WANGDAO_BINARY_QUERY_H__
#define __WANGDAO_BINARY_QUERY_H__


#include "Base.h"
#include "Query.h"

class BinaryQuery : public Base
{
protected:
	BinaryQuery(const Query & lhs, const Query & rhs, const string & oper)
	: _lhs(lhs)
	, _rhs(rhs)
	, _oper(oper)
	{}

	std::ostream & display(std::ostream & os) const{
		return os << "(" << _lhs 
				  << " " << _oper 
				  << " " << _rhs
				  << ")";
	}
	
	const Query _lhs;
	const Query _rhs;
	const string _oper;
};


#endif
