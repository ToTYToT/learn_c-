#include "TcpConnection.h"

#include <iostream>
#define THE_INFO_OF_RUN (std::cout<<"                "<<__func__<<"    "<<__FILE__<<"-->"<<__LINE__<<std::endl)

namespace wd
{
TcpConnection::TcpConnection(int sockfd)
: sockfd_(sockfd),
  sockIO_(sockfd),
  localAddr_(Socket::getLocalAddr(sockfd)),
  peerAddr_(Socket::getPeerAddr(sockfd)),
  isShutdownWrite_(false)
{
		THE_INFO_OF_RUN;

}

TcpConnection::~TcpConnection()
{
		THE_INFO_OF_RUN;
    if(!isShutdownWrite_)
    {
        shutdown();
    }
}

//conn->handleConnectCalback()


void TcpConnection::handleConnectCallback()
{
		THE_INFO_OF_RUN;
    if(onConnectCallback_)
    {
        onConnectCallback_(shared_from_this());
    }
}

void TcpConnection::handleMessageCallback()
{
		THE_INFO_OF_RUN;
    if(onMessageCallback_)
    {
        onMessageCallback_(shared_from_this());
    }
}

void TcpConnection::handleCloseCallback()
{
		THE_INFO_OF_RUN;
    if(onCloseCallback_)
    {
        onCloseCallback_(shared_from_this());
    }
}


ssize_t TcpConnection::readn(char *buf, size_t count)
{
		THE_INFO_OF_RUN;
    ssize_t ret = sockIO_.readn(buf, count);
    if(ret == -1)
    {
        fprintf(stderr, "TcpConnection readn\n");
        exit(EXIT_FAILURE);
    }
    return ret;
}

ssize_t TcpConnection::writen(const char *buf, size_t count)
{
		THE_INFO_OF_RUN;
    ssize_t ret = sockIO_.writen(buf, count);
    if(ret == -1)
    {
        fprintf(stderr, "TcpConnection writen\n");
        exit(EXIT_FAILURE);
    }
    return ret;
}

ssize_t TcpConnection::readLine(char *usrbuf, size_t maxlen)
{
		THE_INFO_OF_RUN;
    ssize_t ret = sockIO_.readline(usrbuf, maxlen);
    if(ret == -1)
    {
        fprintf(stderr, "TcpConnection readLine\n");
        exit(EXIT_FAILURE);
    }
    return ret;
}

std::string TcpConnection::receive()
{
		THE_INFO_OF_RUN;
    char str[1024] = {0};
    int ret = readLine(str, sizeof str);
    if(ret == 0)
        return std::string();
    else
        return std::string(str);
}

void TcpConnection::send(const std::string &s)
{
		THE_INFO_OF_RUN;
    writen(s.c_str(), s.size());
}


std::string TcpConnection::toString() const
{
		THE_INFO_OF_RUN;
    char text[100];
    snprintf(text, sizeof text, "%s:%d -> %s:%d", 
        localAddr_.toIp().c_str(),
        localAddr_.toPort(),
        peerAddr_.toIp().c_str(),
        peerAddr_.toPort());

    return text;
}

}
