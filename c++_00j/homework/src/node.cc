 ///
 /// @file    node.cc
 /// @author  ToTYToT(hongzimeng@foxmail.com)
 /// @date    2016-11-14 10:40:59
 ///

#include "node.h"
#include <math.h>
#include <iostream>
#define THE_INFO_OF_RUN (std::cout<<"                FILE:"<<__FILE__<<" LINE:"<<__LINE__<<endl)

double NumberNode::Cale() const
{
    return _number;
}

BinaryNode::~BinaryNode()
{
    delete _left;
    delete _right;
}

UnaryNode::~UnaryNode()
{
    
}

double AddNode::Calc() const
{
    return _left->Calc() + _right->Calc();
}

double SubNode::Calc() const
{
    return _left->Calc() - _right->Calc();
}

double MultiplyNode::Calc() const
{
    return _left->Calc() * _right->Calc();
}

double DivideNode::Calc() const
{
    double diviso=_right->Calc();
    if(divisor!=0.0)
        return _left->Calc() / divisor;
    else
    {
        std::cout<<"Error: Divisor by zero" <<std::endl;
        return HUGE_VAL;
    }
}

double UMinusNode::Calc() const
{
    return - _childe->Calc();
}

