#include "InetAddress.h"
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#include <iostream>
#define THE_INFO_OF_RUN (std::cout<<"                "<<__func__<<"    "<<__FILE__<<"-->"<<__LINE__<<std::endl)
namespace wd
{
//静态断言
static_assert(sizeof(InetAddress) == sizeof(struct sockaddr_in), "InetAddress Error");

InetAddress::InetAddress(uint16_t port)
{
		THE_INFO_OF_RUN;
    ::memset(&addr_, 0, sizeof addr_);
    addr_.sin_family = AF_INET;
    addr_.sin_addr.s_addr = INADDR_ANY;
    addr_.sin_port = htons(port);
}

InetAddress::InetAddress(const std::string &ip, uint16_t port)
{
		THE_INFO_OF_RUN;
    ::memset(&addr_, 0, sizeof addr_);
    addr_.sin_family = AF_INET;
    addr_.sin_port = htons(port);
    if(inet_aton(ip.c_str(), &addr_.sin_addr) == 0)
    {
        fprintf(stderr, "ip invalid\n");
        exit(EXIT_FAILURE);
    }
}

InetAddress::InetAddress(const struct sockaddr_in &addr)
: addr_(addr)
{
		THE_INFO_OF_RUN;

}

std::string InetAddress::toIp() const
{
		THE_INFO_OF_RUN;
    return inet_ntoa(addr_.sin_addr);
}
    
uint16_t InetAddress::toPort() const
{
		THE_INFO_OF_RUN;
    return ntohs(addr_.sin_port);
}

}
