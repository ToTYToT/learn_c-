 ///
 /// @file    parser.h
 /// @author  ToTYToT(hongzimeng@foxmail.com)
 /// @date    2016-11-13 15:11:46
 ///
 
#ifndef _PARSER_H_
#define _PARSER_H_
#include <memory>
using std::shared_ptr;
class Scanner;
class Node;

enum STATUS
{
	STATUS_OK,
	STATUS_ERROR,
	STATUS_QUIT
};

class Parser
{
	public:
		Parser(Scanner& scanner):scanner_(scanner),tree_(0){}//构造函数
		void Parse(){tree_=Expr();}
		Node* Expr();
		Node* Term();
		Node* Factor();
		double Calculate() const;
	private:
		Scanner& scanner_;//接受输入后的对象,里面有字符串
		shared_ptr<Node> tree_;
		//Node* tree_;//接受解析后的指针
		STATUS status_;//标志输入状态 
}; 
#endif 
