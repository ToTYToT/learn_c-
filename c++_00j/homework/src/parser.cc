 ///
 /// @file    parser.cc
 /// @author  ToTYToT(hongzimeng@foxmail.com)
 /// @date    2016-11-14 11:24:27
 ///
 
#include "parser.h"
#include "scanner.h"
#include "node.h"
#include <cassert>
#include <iostream>
Parser::Parser(Scanner& scanner): _scanner(scanner),_tree(0){}

void Parser::Parse()
{
	_tree = Expr();
}

Node * Parser::Expr()
{
	Node * node = Term();
	EToken token = _scanner.Token(); 
	if (token==TOKEN_PLUS)
	{
		_scanner.Accept();
		Node * nodeRight=Expr();
		node = new AddNode(node, nodeRight);
	}
	else if( token== TOKEN_MINUS)
	{
		_scanner.Accept();
		Node * nodeRight =Expr();
		node =new SubNode(node,nodeRight);
	}
	return node;


}

Node *Parser::Term()
{
	Node * node=Factor();
	EToken token= _scanner.Token();
	if(token==TOKEN_MULTIPLY)
	{
		_scanner.Accept();
		Node * nodeRight = Term();
		node = new MultiplyNode(node,nodeRight);
	}
	else if(token==TOKEN_DIVIDE)
	{
		_scanner.Accept();
		Node * nodeRight=Term();
		node =new DivideNode(node,nodeRight);
	}
	return node;
}

Node * Parser::Factor()
{
	Node * node=0;
	EToken token=_scanner.Token();
	if (token==TOKEN_LPARENTHESIS)
	{
		_scanner.Accept();
		node =Expr();
		if(_scanner.Token()==TOKEN_RPARENTHESIS)
		{
			_scanner.Accept();
		}
		else
		{
			_status=SATAUS_ERROR;
			std::cout<<"missing parenthsis"<<std::endl;
			node=0;
		}
	}
	else if (token ==TOKEN_NUMBER)
	{
		node = new NumberNode (_scanner.Number());
		_scanner.Accept();
	}
	else if(token==TOKEN_MINUS)
	{
		_scanner.Accept();
		node = new UMinusNode(Factor());
	}
	else
	{
		_status=STATUS_ERROR;
		std::cout<<"not a valid expression"<<std::endl;
		node=0;
	}
	return node;
}

double Parser::Calculate() const
{
	assert(_tree !=0);
	return _tree->Calc();
}
