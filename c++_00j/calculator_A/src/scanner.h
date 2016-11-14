/*************************************************************************
    > File Name: /home/t520/project/learn_c-/c++_00j/calculator/src/scanner.h
    > Author:ToTYToT
    > Mail: 240008250@QQ.COM
    > Created Time: Sun 13 Nov 2016 03:13:36 PM CST
 ************************************************************************/

#ifndef _SCANNER_H_
#define _SCANNER_H_
#include <string>

enum EToken
{
	TOKEN_END,
	TOKEN_ERROR,
	TOKEN_NUMBER,
	TOKEN_PLUS,
	TOKEN_MINUS,
	TOKEN_MULTIPLY,
	TOKEN_DIVIDE,
	TOKEN_LPARENTHESIS,
	TOKEN_RPARENTHESIS,
	TOKEN_IDENTIFIER,
	TOKEN_ASSIGN
};

class Scanner
{
	public:
		Scanner(const std::string& buf);
		void Accept();
		double Number() const;
		EToken Token() const;
	private:
		void SkipWhite();//忽略空格
		const std::string buf_;//存储输入字符串
		unsigned int curPos_;//解析字符串时的当前位置
		EToken token_;//字符串中的标志
		double number_;//字符串中的数值
};

#endif 

