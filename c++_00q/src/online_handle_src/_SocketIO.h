 ///
 /// @file    _SocketIO.h
 /// @author  ToTYToT(hongzimeng@foxmail.com)
 /// @date    2016-11-25 10:09:22
 ///
#ifndef _T_SOCKETIO_H
#define _T_SOCKETIO_H
#include <stdio.h>
#include "_THE_INFO_OF_RUN.h"
namespace T520
{
class SocketIO
{
public:
	SocketIO(int sockfd);
	size_t readn(char *buf,size_t count);
	size_t writen(const char *buf,size_t count);
	size_t readline(char *buf,size_t max_len);
private:
	size_t recv_peek(char*buf,size_t count);
	int _sockfd;
};
}
#endif
