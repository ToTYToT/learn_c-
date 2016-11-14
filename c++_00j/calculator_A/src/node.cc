 ///
 /// @file    node.cc
 /// @author  ToTYToT(hongzimeng@foxmail.com)
 /// @date    2016-11-13 11:07:57
 ///

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

MultipleNode::~MultipleNode()
{
	std::vector<Node*>::const_iterator it;
	for (it = childs_.begin(); it != childs_.end(); ++it)
	{
		delete *it;
	}
}

double SumNode::Calc() const
{
	double result = 0.0;
	std::vector<Node*>::const_iterator childIt = childs_.begin();
	std::vector<bool>::const_iterator positiveIt = positives_.begin();

	for (; childIt != childs_.end(); ++childIt, ++positiveIt)
	{
		assert(positiveIt != positives_.end());
		double val = (*childIt)->Calc();
		if (*positiveIt)
			result += val;
		else
			result -= val;
	}
	assert(positiveIt == positives_.end());

	return result;
}

double ProductNode::Calc() const
{
	double result = 1.0;
	std::vector<Node*>::const_iterator childIt = childs_.begin();
	std::vector<bool>::const_iterator positiveIt = positives_.begin();

	for (; childIt != childs_.end(); ++childIt, ++positiveIt)
	{
		assert(positiveIt != positives_.end());
		double val = (*childIt)->Calc();
		if (*positiveIt)
			result *= val;
		else if (val != 0.0)
			result /= val;
		else
		{
			std::cout<<"Division by zero."<<std::endl;
			return HUGE_VAL;
		}

	}
	assert(positiveIt == positives_.end());

	return result;
}

