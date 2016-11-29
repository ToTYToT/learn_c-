 ///
 /// @file    _Socket.cc
 /// @author  ToTYToT(hongzimeng@foxmail.com)
 /// @date    2016-11-25 08:51:03
 ///
#include "_THE_INFO_OF_RUN.h"
#include "_Socket.h"
#include "_InetAddress.h"
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
namespace T520
{
Socket::Socket(int sockfd)
:_sockfd(sockfd)
{
	THE_INFO_OF_RUN;
}
Socket::Socket()
{
	THE_INFO_OF_RUN;
	_sockfd=socket(AF_INET,SOCK_STREAM,0);
	if(-1==_sockfd)
	{
		perror("socket error");
	}
}
Socket::~Socket()
{
	THE_INFO_OF_RUN;
	::close(_sockfd);
}
void Socket::ready(const InetAddress &addr)
{
	THE_INFO_OF_RUN;
	setReuseAddr(true);
	setReusePort(true);
	bindAddress(addr);
	listen();
}
void Socket::bindAddress(const InetAddress &addr)
{
	THE_INFO_OF_RUN;
	if(-1==::bind(_sockfd,(const struct sockaddr*)addr.getSockAddrPtr(),sizeof(InetAddress)))
	{
		perror("bind error");
		::close(_sockfd);
		exit(EXIT_FAILURE);
	}
}
void Socket::listen()
{
	THE_INFO_OF_RUN;
	if(-1==::listen(_sockfd,10))
	{
		perror("listen error");
		::close(_sockfd);
		exit(EXIT_FAILURE);
	}
}
void Socket::setReuseAddr(bool flag)
{
	THE_INFO_OF_RUN;
	int on =(flag?1:0);
	if(::setsockopt(_sockfd,SOL_SOCKET,SO_REUSEADDR,&on,static_cast<socklen_t>(sizeof(on)))==-1)
	{
		perror("setsockopt reuseaddr error");
		::close(_sockfd);
		exit(EXIT_FAILURE);
	}
}
void Socket::setReusePort(bool flag)
{
	THE_INFO_OF_RUN;
#ifdef SO_REUSEPORT
	int on=(flag?1:0);
	if(::setsockopt(_sockfd,SOL_SOCKET,SO_REUSEPORT,&on,static_cast<socklen_t>(sizeof(on)))==-1)
	{
		perror("setsockopt reuseport error");
		::close(_sockfd);
		exit(EXIT_FAILURE);
	}
#else
	if(flag)
	{
		fprintf(stderr,"SO_REUSEPORT is not supported!\n");
	}
#endif
}
int Socket::accept()
{
	THE_INFO_OF_RUN;
	int peerfd=::accept(_sockfd,NULL,NULL);
	if(-1==peerfd)
	{
		perror("accept error");
		::close(_sockfd);
	}
	return peerfd;
}
void Socket::shutdownWrite()
{
	THE_INFO_OF_RUN;
	if(::shutdown(_sockfd,SHUT_WR)==-1)
	{
		perror("shutdown write error");
	}
}
InetAddress Socket::getLocalAddr(int sockfd)
{
	THE_INFO_OF_RUN;
	struct sockaddr_in addr;
	socklen_t len=sizeof(sockaddr_in);
	if(::getsockname(sockfd,(struct sockaddr*)&addr,&len)==-1)
	{
		perror("getsockname error");
	}
	return InetAddress(addr);
}
InetAddress Socket::getPeerAddr(int sockfd)
{
	THE_INFO_OF_RUN;
	struct sockaddr_in addr;
	socklen_t len=sizeof(sockaddr_in);
	if(::getpeername(sockfd,(struct sockaddr *)&addr,&len)==-1)
	{
		perror("getpeername error");
	}
	return InetAddress(addr);
}
}

