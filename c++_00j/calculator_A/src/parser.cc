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

Parser::Parser(Scanner& scanner) : scanner_(scanner), tree_(0)
{
}

void Parser::Parse()
{
	tree_ = Expr();
}

Node* Parser::Expr()
{
	Node* node = Term();
	EToken token = scanner_.Token();
	//if (token == TOKEN_PLUS)
	//{
	//TOKEN_PLUSscanner_.Accept();
	//AcceptNode* nodeRight = Expr();
	//Exprnode = new AddNode(node, nodeRight);
	//}
	//else if (token == TOKEN_MINUS)
	//{
	//TOKEN_MINUSscanner_.Accept();
	//AcceptNode* nodeRight = Expr();
	//Exprnode = new SubNode(node, nodeRight);
	//}
	if (token == TOKEN_PLUS || token == TOKEN_MINUS)
	{
		// Expr := Term { ('+' | '-') Term }
		MultipleNode* multipleNode = new SumNode(node);
		do 
		{
			scanner_.Accept();
			Node* nextNode = Term();
			multipleNode->AppendChild(nextNode, (token == TOKEN_PLUS));
			token = scanner_.Token();
		} while (token == TOKEN_PLUS || token == TOKEN_MINUS);
		node = multipleNode;
	}

	return node;
}



Node* Parser::Term()
{
	Node* node = Factor();
	EToken token = scanner_.Token();
	//if (token == TOKEN_MULTIPLY)
	//{
	//TOKEN_MULTIPLYscanner_.Accept();
	//AcceptNode* nodeRight = Term();
	//Termnode = new MultiplyNode(node, nodeRight);
	//}
	//else if (token == TOKEN_DIVIDE)
	//{
	//TOKEN_DIVIDEscanner_.Accept();
	//AcceptNode* nodeRight = Term();
	//Termnode = new DivideNode(node, nodeRight);
	//}
	if (token == TOKEN_MULTIPLY || token == TOKEN_DIVIDE)
	{
		// Term := Factor { ('*' | '/') Factor }
		MultipleNode* multipleNode = new ProductNode(node);
		do 
		{
			scanner_.Accept();
			Node* nextNode = Factor();
			multipleNode->AppendChild(nextNode, (token == TOKEN_MULTIPLY));
			token = scanner_.Token();
		} while (token == TOKEN_MULTIPLY || token == TOKEN_DIVIDE);
		node = multipleNode;
	}

	return node;
}

Node* Parser::Factor()
{
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
			// Todo:抛出异常
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
		// Todo:抛出异常
		std::cout<<"not a valid expression"<<std::endl;
		node = 0;
	}
	return node;
}

double Parser::Calculate() const
{
	assert(tree_ != 0);
	return tree_->Calc();
}

