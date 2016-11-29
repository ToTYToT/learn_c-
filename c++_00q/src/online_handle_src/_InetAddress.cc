 ///
 /// @file    _InetAddress.cc
 /// @author  ToTYToT(hongzimeng@foxmail.com)
 /// @date    2016-11-25 08:25:22
 ///
 
#include "_THE_INFO_OF_RUN.h"
#include "_InetAddress.h"
#include <stdio.h>
#include <stdlib.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <string.h>
namespace T520
{
InetAddress::InetAddress(short port)
{
	THE_INFO_OF_RUN;
	::memset(&_addr,0,sizeof(_addr));
	_addr.sin_family=AF_INET;
	_addr.sin_port=htons(port);
	_addr.sin_addr.s_addr=INADDR_ANY;
}
InetAddress::InetAddress(const char *pIp,short port)
{
	THE_INFO_OF_RUN;
	::memset(&_addr,0,sizeof(_addr));
	_addr.sin_family=AF_INET;
	_addr.sin_port=htons(port);
	_addr.sin_addr.s_addr=inet_addr(pIp);
}
InetAddress::InetAddress(const struct sockaddr_in &addr)
{
	THE_INFO_OF_RUN;
}
const struct sockaddr_in *InetAddress::getSockAddrPtr() const
{
	THE_INFO_OF_RUN;
	return &_addr;
}
std::string InetAddress::ip() const
{
	THE_INFO_OF_RUN;
	return std::string(inet_ntoa(_addr.sin_addr));
}
unsigned short InetAddress::port() const
{
	THE_INFO_OF_RUN;
	return ntohs(_addr.sin_port);
}
}
