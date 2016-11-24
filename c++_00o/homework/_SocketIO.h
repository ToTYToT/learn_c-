 ///
 /// @file    _SocketIO.h
 /// @author  ToTYToT(hongzimeng@foxmail.com)
 /// @date    2016-11-23 22:21:36
 ///
#ifndef SOCKETIO_H_
#define SOCKETIO_H_

#include "_Noncopyable.h"
#include <sys/types.h>
#include <iostream>
#define THE_INFO_OF_RUN (std::cout<<"                "<<__func__<<"    "<<__FILE__<<"-->"<<__LINE__<<std::endl)
using std::cout;
using std::endl;
namespace wd
{
class SocketIO: Noncopyable
	{
		public:
		explicit SocketIO(int sockfd)
		:_sockfd(sockfd)
		{
		}
		ssize_t readn(char *buf,size_t count);
		ssize_t writen(const char *buf,size_t count);
		ssize_t readline(char *usrbuf,size_t maxlen);
		private:
		ssize_t recv_peek(char *buf,size_t len);
		const int _sockfd;
	};
}
#endif
