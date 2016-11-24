 ///
 /// @file    _Socket.cc
 /// @author  ToTYToT(hongzimeng@foxmail.com)
 /// @date    2016-11-23 21:25:46
 ///
 
#include "_Socket.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>
#include <unistd.h>
#include <errno.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <netinet/tcp.h>
#include <netdb.h>
#include <iostream>
#define THE_INFO_OF_RUN (std::cout<<"                "<<__func__<<"    "<<__FILE__<<"-->"<<__LINE__<<std::endl)
using std::cout;
using std::endl;
namespace wd
{
	Socket::Socket(int sockfd)
		:_sockfd(sockfd)
	{
	}
	Socket::~Socket()
	{
		::close(_sockfd);
	}
	void Socket::bindAddress(const InetAddress &addr)
	{
		if(::bind(_sockfd,(SA*)addr.getSockAddrInet(),sizeof(addr))==-1)
		{
			fprintf(stderr,"bind address error\n");
			exit(EXIT_FAILURE);
		}
	}
	void Socket::listen()
	{
		if(::listen(_sockfd,SOMAXCONN)==-1)
		{
			fprintf(stderr,"listen address error\n");
			exit(EXIT_FAILURE);
		}
	}
	int Socket::accept()
	{
		int fd= ::accept(_sockfd,NULL,NULL);
		if(fd==-1)
		{
			fprintf(stderr,"accept error\n");
			exit(EXIT_FAILURE);
		}
		return fd;
	}
	void Socket::shutdownWrite()
	{
		if(::shutdown(_sockfd,SHUT_WR)==-1)
		{
			fprintf(stderr,"shutdown error\n");
			exit(EXIT_FAILURE);
		}
	}
	void Socket::setTcpNoDelay(bool on)
	{
		int optval =on?1:0;
		if(::setsockopt(_sockfd,IPPROTO_TCP,TCP_NODELAY,&optval,static_cast<socklen_t>(sizeof optval))==-1)
		{
			fprintf(stderr,"setTcpNoDelay error\n");
			exit(EXIT_FAILURE);
		}
	}
	void Socket::setReuseAddr(bool on)
	{
		int optval = on ? 1:0;
		if(::setsockopt(_sockfd,SOL_SOCKET,SO_REUSEADDR,&optval,static_cast<socklen_t>(sizeof optval))==-1)
		{
			fprintf(stderr,"setReuseAddr error\n");
			exit(EXIT_FAILURE);
		}
	}
	void Socket::setReusePort(bool on)
	{
#ifdef SO_REUSEPORT
		int optval =on?1:0;
		int ret=::setsockopt(_sockfd,SOL_SOCKET,SO_REUSEPORT,&optval,static_cast<socklen_t>(sizeof optval));
		if(ret<0)
		{
			fprintf(stderr,"setReusePort error\n");
			exit(EXIT_FAILURE);
		}
#else
		if(on)
		{
			fprintf(stderr,"SO_REUSEPORT is not supported.\n");
		}
#endif
	}
	void Socket::setKeepAlive(bool on)
	{
		int optval=on?1:0;
		if(::setsockopt(_sockfd,SOL_SOCKET,SO_KEEPALIVE,&optval,static_cast<socklen_t>(sizeof optval))==-1)
		{
			fprintf(stderr,"setKeepAlive error\n");
			exit(EXIT_FAILURE);
		}
	}
	InetAddress Socket::getLocalAddr(int sockfd)
	{
		struct sockaddr_in addr;
		socklen_t len=sizeof addr;
		if(::getsockname(sockfd,(SA*)&addr,&len)==-1)
		{
			fprintf(stderr,"getLocalAddress\n");
			exit(EXIT_FAILURE);
		}
		return InetAddress(addr);
	}
	InetAddress Socket::getPeerAddr(int sockfd)
	{
		struct sockaddr_in addr;
		socklen_t len=sizeof addr;
		if(::getpeername(sockfd,(SA*)&addr,&len)==-1)
		{
			fprintf(stderr,"getPeerAddress\n");
			exit(EXIT_FAILURE);
		}
		return InetAddress(addr);
	}
}
