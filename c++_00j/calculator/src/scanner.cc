
//2. Scanner实现文件
#include "scanner.h"
#include <stdlib.h>

#if 0
Scanner::Scanner(const std::string& buf) : buf_(buf), curPos_(0)
{
	Accept();//解析出第一个标志
}

double Scanner::Number() const
{
	return number_;//返回数值
}

EToken Scanner::Token() const
{
	return token_;//返回标志
}
#endif

void Scanner::SkipWhite()//忽略空格
{
	while (isspace(buf_[curPos_]))
		++curPos_;
}

void Scanner::Accept()//逐字符解析
{
	SkipWhite();
	switch (buf_[curPos_])
	{
		case '+':
			token_ = TOKEN_PLUS;
			++curPos_;
			break;
		case '-':
			token_ = TOKEN_MINUS;
			++curPos_;
			break;
		case '*':
			token_ = TOKEN_MULTIPLY;
			++curPos_;
			break;
		case '/':
			token_ = TOKEN_DIVIDE;
			++curPos_;
			break;
		case '(':
			token_ = TOKEN_LPARENTHESIS;
			++curPos_;
			break;
		case ')':
			token_ = TOKEN_RPARENTHESIS;
			++curPos_;
			break;
		case '0': case '1': case '2': case '3': case '4':
		case '5': case '6': case '7': case '8': case '9':
		case '.':
			token_ = TOKEN_NUMBER;
			char* p;
			number_ = strtod(&buf_[curPos_], &p);
			curPos_ = p - &buf_[0];
			break;
		case '\0': case '\n': case '\r': case EOF:
			token_ = TOKEN_END;
			break;
		default:
			token_ = TOKEN_ERROR;
			break;
	}
}

