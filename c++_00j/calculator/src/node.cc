 ///
 /// @file    node.cc
 /// @author  ToTYToT(hongzimeng@foxmail.com)
 /// @date    2016-11-13 11:07:57
 ///

#if 0
#include "node.h"
#include <math.h>
#include <iostream>

double NumberNode::Calc() const
{
	return number_;
}

BinaryNode::~BinaryNode()
{
	delete left_;
	delete right_;
}

UnaryNode::~UnaryNode()
{

}

double AddNode::Calc() const
{
	return left_->Calc() + right_->Calc();
}

double SubNode::Calc() const
{
	return left_->Calc() - right_->Calc();
}

double MultiplyNode::Calc() const
{
	return left_->Calc() * right_->Calc();
}

double DivideNode::Calc() const
{
	double divisor = right_->Calc();
	if (divisor != 0.0)
		return left_->Calc() / divisor;
	else
	{
		std::cout<<"Error: Divisor by zero"<<std::endl;
		return HUGE_VAL;
	}
}

double UMinusNode::Calc() const
{
	return - child_->Calc();
}
#endif
