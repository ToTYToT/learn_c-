 ///
 /// @file    _InetAddress.h
 /// @author  ToTYToT(hongzimeng@foxmail.com)
 /// @date    2016-11-25 08:35:08
 ///
#ifndef __T_INETADDRESS_H__
#define __T_INETADDRESS_H__
#include "_THE_INFO_OF_RUN.h"
#include <netinet/in.h>
#include <string>
namespace T520
{
class InetAddress
{
public:
	InetAddress(short port);
	InetAddress(const char * pIp,short port);
	InetAddress(const struct sockaddr_in &addr);
	const struct sockaddr_in *getSockAddrPtr() const;
	std::string ip() const;
	unsigned short port() const;
private:
	struct sockaddr_in _addr;
};
}
#endif
