 ///
 /// @file    _InetAddress.h
 /// @author  ToTYToT(hongzimeng@foxmail.com)
 /// @date    2016-11-23 21:19:38
 ///
 
#ifndef INET_ADDRESS_H_
#define INET_ADDRESS_H_

#include <string>
#include <netinet/in.h>
#include <iostream>
#define THE_INFO_OF_RUN (std::cout<<"                "<<__func__<<"    "<<__FILE__<<"-->"<<__LINE__<<std::endl)
using std::cout;
using std::endl;
typedef struct sockaddr SA;
typedef struct sockaddr_in SAI;
namespace wd
{
	class InetAddress
	{
		public:
			explicit InetAddress(uint16_t port);
			InetAddress(const std::string &ip, uint16_t port);
			InetAddress(const struct sockaddr_in &addr);
			//{ _addr=addr;}
			const struct sockaddr_in * getSockAddrInet() const
			{ return &_addr;}
			std::string toIp() const;
			uint16_t toPort() const;
		private:
			struct sockaddr_in _addr;
	};
}
#endif
