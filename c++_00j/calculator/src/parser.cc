 ///
 /// @file    parser.cc
 /// @author  ToTYToT(hongzimeng@foxmail.com)
 /// @date    2016-11-13 11:14:18
 ///

#include "parser.h"
#include "scanner.h"
#include "node.h"
#include <cassert>
#include <iostream>
int e_cout_num;
int t_cout_num;
int f_cout_num;
#if 0
Parser::Parser(Scanner& scanner) : scanner_(scanner), tree_(0)
{
}

void Parser::Parse()
{
	tree_ = Expr();
}
#endif
Node* Parser::Expr()
{
	++e_cout_num;
	Node* node = Term();
	EToken token = scanner_.Token();
	if (token == TOKEN_PLUS)
	{
		scanner_.Accept();
		Node* nodeRight = Expr();
		node = new AddNode(node, nodeRight);
	}
	else if (token == TOKEN_MINUS)
	{
		scanner_.Accept();
		Node* nodeRight = Expr();
		node = new SubNode(node, nodeRight);
	}
	return node;
}

Node* Parser::Term()
{
	++t_cout_num;
	Node* node = Factor();
	EToken token = scanner_.Token();
	if (token == TOKEN_MULTIPLY)
	{
		scanner_.Accept();
		Node* nodeRight = Term();
		node = new MultiplyNode(node, nodeRight);
	}
	else if (token == TOKEN_DIVIDE)
	{
		scanner_.Accept();
		Node* nodeRight = Term();
		node = new DivideNode(node, nodeRight);
	}
	return node;
}

Node* Parser::Factor()
{
	++f_cout_num;
	Node* node = 0;
	EToken token = scanner_.Token();
	if (token == TOKEN_LPARENTHESIS)
	{
		scanner_.Accept();//scanner_// accept '('
			node = Expr();
		if (scanner_.Token() == TOKEN_RPARENTHESIS)
		{
			scanner_.Accept();//Accept// accept ')'
		}
		else
		{
			status_ = STATUS_ERROR;
			std::cout<<"missing parenthesis"<<std::endl;
			node = 0;
		}
	}
	else if (token == TOKEN_NUMBER)
	{
		node = new NumberNode(scanner_.Number());
		scanner_.Accept();
	}
	else if (token == TOKEN_MINUS)
	{
		scanner_.Accept();//scanner_// accept minus
			node = new UMinusNode(Factor());
	}
	else
	{
		status_ = STATUS_ERROR;
		std::cout<<"not a valid expression"<<std::endl;
		node = 0;
	}
	return node;
}
#if 1
double Parser::Calculate() const
{
	assert(tree_ != 0);
	std::cout<<e_cout_num<<std::endl;
	std::cout<<t_cout_num<<std::endl;
	std::cout<<f_cout_num<<std::endl;
	return tree_->Calc();
}
#endif
