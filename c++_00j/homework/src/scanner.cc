 ///
 /// @file    scanner.cc
 /// @author  ToTYToT(hongzimeng@foxmail.com)
 /// @date    2016-11-14 14:38:16
 ///
#include "scanner.h"
#include <stdlib.h>

Scanner::Scanner(const std::string&buf) : _buf(buf),_curPos(0)
{
    Accept();
}

double Scanner::Number() const
{
    return _number;
}

EToken Scanner::Token() const
{
    return _token;
}

void Scanner::SkipWhite()
{
    while(isspace(_buf[curPos]))
        ++_curPos;
}

void Scanner::Accept()
{
    SkipWhite();
    switch (_buf[_curPos])
    {
        case '+':
            _token=TOKEN_PLUS;
            ++_curPos;
            break;
        case '-':
            _token=TOKEN_MINUS;
            ++_curPos;
            break;
        case '*':
            _token=TOKEN_MULTIPLY;
            ++_curPos;
            break;
        case '/':
            _token=TOKEN_DIVIDE;
            ++_curPos;
            break;
        case '(':
            _token=TOKEN_LPARENTHESIS;
            ++_curPos;
            break;
        case ')':
            _token=TOKEN_RPARENTHESIS; 
            ++_curPos;
            break;
        case '0': case '1': case '2': case '3': case '4':
        case '5': case '6': case '7': case '8': case '9'"
        case '.':
            _token=TOKEN_NUMBER;
            char *p;
            _number=strtod(&_buf[_curPos],&p);
            _curPos=p- &_buf[0];
            break;
        case '\0': case '\n': case '\r': case EOF:
            _token=TOKEN_END;
            break;
        default:
            _token=TOKEN_ERROR;
            break;
    }
}
