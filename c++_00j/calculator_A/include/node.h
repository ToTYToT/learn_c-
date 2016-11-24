// 
/// @file    node.h
/// @author  ToTYToT(hongzimeng@foxmail.com)
/// @date    2016-11-13 15:10:06
///
#ifndef _NODE_H_
#define _NODE_H_

#include <cassert>
#include <vector>
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
		double Calc() const;
	private:
		const double number_;
};


class UnaryNode : public Node
{
	public:
		UnaryNode(Node* child)
			: child_(child) {}
		~UnaryNode();
	protected:
		Node* const child_;
};

class UMinusNode : public UnaryNode
{
	public:
		UMinusNode(Node* child)
			: UnaryNode(child) {}
		double Calc() const;
};

class MultipleNode : public Node
{
	public:
		MultipleNode(Node* node)
		{
			AppendChild(node, true);
		}
		void AppendChild(Node* node, bool positive)
		{
			childs_.push_back(node);
			positives_.push_back(positive);
		}
		~MultipleNode();
	protected:
		std::vector<Node*> childs_;
		std::vector<bool> positives_;
};

class SumNode : public MultipleNode
{
	public:
		SumNode(Node* node)
			: MultipleNode(node) {}
		double Calc() const;
};

class ProductNode : public MultipleNode
{
	public:
		ProductNode(Node* node)
			: MultipleNode(node) {}
		double Calc() const;
};
#endif 
