 ///
 /// @file    Socket.cc
 /// @author  lemon(haohb13@gmail.com)
 /// @date    2015-11-04 17:42:38
 ///

#include "THE_INFO_OF_RUN.h" 
#include "Socket.h"
#include "InetAddress.h"
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

namespace wd
{
Socket::Socket(int sockfd) : sockfd_(sockfd){}

Socket::Socket()
{
	THE_INFO_OF_RUN;
	sockfd_ = socket(AF_INET, SOCK_STREAM, 0);
	if(-1 == sockfd_)
	{
		perror("socket error");
	}
}

Socket::~Socket()
{
	THE_INFO_OF_RUN;
	::close(sockfd_);
}

void Socket::ready(const InetAddress & addr)
{
	THE_INFO_OF_RUN;
	setReuseAddr(true);
	setReusePort(true);
	bindAddress(addr);
	listen();
}


void Socket::bindAddress(const InetAddress & addr)
{
	THE_INFO_OF_RUN;
	if(-1 == ::bind(sockfd_, (const struct sockaddr*)addr.getSockAddrPtr(), sizeof(InetAddress)))
	{
		perror("bind error");
		::close(sockfd_);
		exit(EXIT_FAILURE);
	}
}


void Socket::listen()
{
	THE_INFO_OF_RUN;
	if(-1 == ::listen(sockfd_, 10))
	{
		perror("listen error");
		::close(sockfd_);
		exit(EXIT_FAILURE);
	}
}

void Socket::setReuseAddr(bool flag)
{
	THE_INFO_OF_RUN;
	int on = (flag ? 1 : 0);
	if(::setsockopt(sockfd_, 
					SOL_SOCKET, 
					SO_REUSEADDR, 
					&on, 
					static_cast<socklen_t>(sizeof(on))) == -1)
	{
		perror("setsockopt reuseaddr error");
		::close(sockfd_);
		exit(EXIT_FAILURE);
	}
}

void Socket::setReusePort(bool flag)
{
	THE_INFO_OF_RUN;
#ifdef SO_REUSEPORT
	int on = (flag ? 1 : 0);
	if(::setsockopt(sockfd_, 
				    SOL_SOCKET,
					SO_REUSEPORT,
					&on,
					static_cast<socklen_t>(sizeof(on))) == -1)
	{
		perror("setsockopt reuseport error");
		::close(sockfd_);
		exit(EXIT_FAILURE);
	}
#else
	if(flag)
	{
		fprintf(stderr, "SO_REUSEPORT is not supported!\n");
	}
#endif
}

int Socket::accept()
{
	THE_INFO_OF_RUN;
	int peerfd = ::accept(sockfd_, NULL, NULL);	
	if(-1 == peerfd)
	{
		perror("accept error");
		::close(sockfd_);
	}
	return peerfd;
}

void Socket::shutdownWrite()
{
	THE_INFO_OF_RUN;
	if(::shutdown(sockfd_, SHUT_WR) == -1)
	{
		perror("shutdown write error");
		//exit(EXIT_FAILURE);//若peer端已关闭，会导致server端崩溃
	}
}

InetAddress Socket::getLocalAddr(int sockfd)
{
	THE_INFO_OF_RUN;
	struct sockaddr_in addr;
	socklen_t len = sizeof(sockaddr_in);
	if(::getsockname(sockfd, (struct sockaddr *)&addr, &len) == -1)
	{
		perror("getsockname error");
	}
	return InetAddress(addr);
}

InetAddress Socket::getPeerAddr(int sockfd)
{
	THE_INFO_OF_RUN;
	struct sockaddr_in addr;
	socklen_t len = sizeof(sockaddr_in);
	if(::getpeername(sockfd, (struct sockaddr *)&addr, &len) == -1)
	{
		perror("getpeername error");
	}
	return InetAddress(addr);
}

}// end of namespace wd
