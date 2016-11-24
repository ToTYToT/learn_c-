 ///
 /// @file    _InetAddress.cc
 /// @author  ToTYToT(hongzimeng@foxmail.com)
 /// @date    2016-11-23 21:13:35
 ///
 
#include "_InetAddress.h"
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <iostream>
#define THE_INFO_OF_RUN (std::cout<<"                "<<__func__<<"    "<<__FILE__<<"-->"<<__LINE__<<std::endl)
using std::cout;
using std::endl;
namespace wd
{
	static_assert(sizeof(InetAddress)==sizeof(struct sockaddr_in),"InetAddress Error");
	InetAddress::InetAddress(uint16_t port)
	{
		::memset(&_addr,0,sizeof _addr);
		_addr.sin_family=AF_INET;
		_addr.sin_addr.s_addr=INADDR_ANY;
		_addr.sin_port=htons(port);
	}
	InetAddress::InetAddress(const std::string &ip,uint16_t port)
	{
		::memset(&_addr,0,sizeof _addr);
		_addr.sin_family=AF_INET;
		_addr.sin_port=htons(port);
		if(inet_aton(ip.c_str(),&_addr.sin_addr)==0)
		{
			fprintf(stderr,"ip invalid\n");
			exit(EXIT_FAILURE);
		}
	}
	InetAddress::InetAddress(const struct sockaddr_in &addr)
	:_addr(addr)
	{
	}
	std::string InetAddress::toIp() const
	{
		return inet_ntoa(_addr.sin_addr);
	}
	uint16_t InetAddress::toPort() const
	{
		return ntohs(_addr.sin_port);
	}
}
