 ///
 /// @file    scanner.h
 /// @author  ToTYToT(hongzimeng@foxmail.com)
 /// @date    2016-11-14 14:54:36
 ///

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
		Scanner(const std::string&buf);
		void Accept();
		double Number() const;
		EToken Token() const;
	private:
		void SkipWhite();
		const std::string _buf;
		unsigned int _curPos;
		EToken _token;
		double _number;
};

#endif

