#include "TcpServer.h"

#include <iostream>
#define THE_INFO_OF_RUN (std::cout<<"                "<<__func__<<"    "<<__FILE__<<"-->"<<__LINE__<<std::endl)

namespace
{
int createSocketFd()
{
		THE_INFO_OF_RUN;
    int fd = ::socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
    if(fd == -1)
    {
        fprintf(stderr, "create socket fd error\n");
        exit(EXIT_FAILURE);
    }

    return fd;
}
}


namespace wd
{
TcpServer::TcpServer(const string & ip, unsigned short port)
: addr_(ip, port)
, sockfd_(createSocketFd())
, poller_(sockfd_.fd())
{
		THE_INFO_OF_RUN;
    sockfd_.setTcpNoDelay(false);
    sockfd_.setReusePort(true);
    sockfd_.setReuseAddr(true);
    sockfd_.setKeepAlive(false);

    sockfd_.bindAddress(addr_);
    sockfd_.listen();
}

}
