 ///
 /// @file    node.h
 /// @author  ToTYToT(hongzimeng@foxmail.com)
 /// @date    2016-11-13 15:10:06
 ///

#ifndef _NODE_H_
#define _NODE_H_

#include <math.h>
#include <iostream>
#include <memory>
using std::shared_ptr;
class Noncopyable
{
	protected:
		Noncopyable(){}
		~Noncopyable(){}
	private:
		Noncopyable(const Noncopyable &);
		Noncopyable &operator=(const Noncopyable &);
};

class Node : private Noncopyable
{
	public:
		virtual double Calc() const = 0;
		virtual ~Node() {};
};

class NumberNode : public Node
{
	public:
		NumberNode(double number) : number_(number) {}
		double Calc() const{return number_;}
	private:
		const double number_;
};

class BinaryNode : public Node
{
	public:
		BinaryNode(Node* left, Node* right): left_(left), right_(right) {}
	//	~BinaryNode()
	//	{
	//		//delete left_;
	//		//delete right_;
	//	}
	protected:
		shared_ptr<Node> left_;
		shared_ptr<Node> right_;
		//Node* const left_;
		//Node* const right_;
};

class UnaryNode : public Node
{
	public:
		UnaryNode(Node* child)
			: child_(child) {}
		~UnaryNode(){};
	protected:
		shared_ptr<Node> child_;
		//Node* const child_;
};

class AddNode : public BinaryNode
{
	public:
		AddNode(Node* left, Node* right)
			: BinaryNode(left, right) {}
		double Calc() const{return left_->Calc()+right_->Calc();}
};

class SubNode : public BinaryNode
{
	public:
		SubNode(Node* left, Node* right)
			: BinaryNode(left, right) {}
		double Calc() const{return left_->Calc()-right_->Calc();}
};

class MultiplyNode : public BinaryNode
{
	public:
		MultiplyNode(Node* left, Node* right)
			: BinaryNode(left, right) {}
		double Calc() const{return left_->Calc()+right_->Calc();}
};

class DivideNode : public BinaryNode
{
	public:
		DivideNode(Node* left, Node* right)
			: BinaryNode(left, right) {}
		double Calc() const
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
};

class UMinusNode : public UnaryNode
{
	public:
		UMinusNode(Node* child)
			: UnaryNode(child) {}
		double Calc() const{return -child_->Calc();}
};

#endif // _NODE_H_
