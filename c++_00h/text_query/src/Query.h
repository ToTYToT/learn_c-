 ///
 /// @file    Query.h
 /// @author  lemon(haohb13@gmail.com)
 /// @date    2016-11-09 10:58:33
 ///

//VS上用
//#pragma once
 
#ifndef __WANGDAO_QUERY_H__
#define __WANGDAO_QUERY_H__


#include <iostream>
#include <string>
#include <set>
#include <memory>
using std::cout;
using std::endl;
using std::string;
using std::shared_ptr;
using std::set;

class Base;
class TextQuery;

class Query{
#if 1
	//在这些函数内部调用 Query(Base *)
	friend Query operator~(const Query &);
	friend Query operator|(const Query & lhs, const Query & rhs);
	friend Query operator&(const Query & lhs, const Query & rhs);
#endif

	friend std::ostream & operator<<(std::ostream & os, const Query & rhs);
public:
	Query(const string & word);

	set<int> doQuery(const TextQuery & tq)const;
	std::ostream & display(std::ostream & os) const;

private:
	Query(Base * pBase);//运算符重载时使用
	
private:
	shared_ptr<Base> _basePtr;
};

Query operator~(const Query &);
Query operator|(const Query & lhs, const Query & rhs);
Query operator&(const Query & lhs, const Query & rhs);

void showResult(const TextQuery & tq, const set<int> & numbers);

#endif
