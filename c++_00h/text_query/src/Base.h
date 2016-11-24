 ///
 /// @file    Base.h
 /// @author  lemon(haohb13@gmail.com)
 /// @date    2016-11-09 11:02:36
 ///
 
#ifndef __WANDAO_BASE_H__
#define __WANDAO_BASE_H__

#include "TextQuery.h"

#include <iostream>
#include <set>
using std::set;

class Base
{
	friend class Query;
protected:
	virtual
	set<int> doQuery(const TextQuery & tq) const=0;
	
	virtual
	std::ostream & display(std::ostream & os) const=0;
};


#endif
