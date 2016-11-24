 ///
 /// @file    _TcpServer.cc
 /// @author  ToTYToT(hongzimeng@foxmail.com)
 /// @date    2016-11-23 22:53:44
 ///
 
#include "_TcpServer.h"
#include <iostream>
#define THE_INFO_OF_RUN (std::cout<<"                "<<__func__<<"    "<<__FILE__<<"-->"<<__LINE__<<std::endl)
using std::cout;
using std::endl;
namespace wd
{
	int createSocketFd()
	{
		int fd=::socket(AF_INET,SOCK_STREAM,IPPROTO_TCP);
		if(fd==-1)
		{
			fprintf(stderr,"create socket fd error\n");
			exit(EXIT_FAILURE);
		}
		return fd;
	}
}
namespace wd
{
	TcpServer::TcpServer(const std::string &ip,unsigned short port)
		:_addr(ip,port)
		 ,_sockfd(createSocketFd())
		 ,_poller(_sockfd.fd())
	{
		_sockfd.setTcpNoDelay(false);
		_sockfd.setReusePort(true);
		_sockfd.setReuseAddr(true);
		_sockfd.setKeepAlive(false);
		_sockfd.bindAddress(_addr);
		_sockfd.listen();
	}
}
