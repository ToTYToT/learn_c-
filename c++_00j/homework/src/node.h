 /// @file    node.h
 /// @author  ToTYToT(hongzimeng@foxmail.com)
 /// @date    2016-11-14 10:53:06
 ///
#ifndef _NODE_H_
#define _NODE_H_

class Noncopyable
{
	protected:
		Noncoyable(){}
		~Noncopyable(){}
	private:
		Noncopyable(const Noncopyable &);
		Noncopyable &operator=(const Noncopyable&);
};

class Node : private Noncopyable
{
	public:
		virtual double Calc() const =0;
		virtual ~Node() {};
};

class NumberNode : public node
{
	public:
		NumberNode(double number) : _number(number){}
		double Calc() const;
	private:
		const double _number;
};

class BinaryNode : public Node
{
	public:
		BinaryNode(Node * left, Node * right)
			:_left(left),_right(right){}
		~BinaryNode();
};

class UnaryNode : public Node
{
	public:
		UnaryNode(Node * child)
			: _child(child){}
		~UnaryNode();
	protected:
		Node * const _child;
};

class AddNode : public BinaryNode
{
	public:
		AddNode(Node* left,Node * right)
			: BinaryNode(left,right){}
		double Calc() const;

};

class SubNode : public BinaryNode
{
	public:
		SubNode(Node * left, Node *right)
			: BinaryNode(left,right){}
		double Calc() const;
};

class MultiplyNode : public BinaryNode
{
	public:
		MultiplyNode(Node * left, Node * right)
			: BinaryNode(left,right){}
		double Calc() const;
};

class DivideNode : public BinaryNode
{
	public:
		DivideNode(Node * left,Node * right)
			:BinaryNode(left,right){}
		double Calc() const;
};

class UMinusNode : public UnaryNode
{
	public:
		UMinusNode(Node* child)
			: UnarNode(child){}
		double Calc() const;
};
#endif
