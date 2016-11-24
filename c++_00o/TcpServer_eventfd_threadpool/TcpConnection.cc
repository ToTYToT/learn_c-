 ///
 /// @file    TcpConnection.cc
 /// @author  lemon(haohb13@gmail.com)
 /// @date    2015-11-05 17:02:41
 ///

#include "THE_INFO_OF_RUN.h" 
#include "TcpConnection.h"
#include "EpollPoller.h"
#include <string.h>
#include <stdio.h>


namespace wd
{

TcpConnection::TcpConnection(int sockfd, EpollPoller * loop)
: sockfd_(sockfd)
, sockIO_(sockfd)
, localAddr_(wd::Socket::getLocalAddr(sockfd))
, peerAddr_(wd::Socket::getPeerAddr(sockfd))
, isShutdownWrite_(false)
, loop_(loop)
{
THE_INFO_OF_RUN;
}


TcpConnection::~TcpConnection()
{
THE_INFO_OF_RUN;
	if(!isShutdownWrite_)
	{
		isShutdownWrite_ = true;
		shutdown();
	}
	printf("~TcpConnection()\n");
}

std::string TcpConnection::receive()
{
THE_INFO_OF_RUN;
	char buf[1024];
	memset(buf, 0, sizeof(buf));
	size_t ret = sockIO_.readline(buf, sizeof(buf));
	if(ret == 0)
	{
		return std::string();
	}
	else
		return std::string(buf);
}

void TcpConnection::send(const std::string & msg)
{
THE_INFO_OF_RUN;
	sockIO_.writen(msg.c_str(), msg.size());
}

//针对php服务器
void TcpConnection::sendAndClose(const std::string & msg)
{
THE_INFO_OF_RUN;
	send(msg);
	shutdown();
}

void TcpConnection::sendInLoop(const std::string & msg)
{
THE_INFO_OF_RUN;
	//loop_->runInLoop(std::bind(&TcpConnection::sendAndClose, this, msg));
	loop_->runInLoop(std::bind(&TcpConnection::send, this, msg));
}

void TcpConnection::shutdown()
{
THE_INFO_OF_RUN;
	if(!isShutdownWrite_)
		sockfd_.shutdownWrite();
	isShutdownWrite_ = true;
}

std::string TcpConnection::toString()
{
THE_INFO_OF_RUN;
	char str[100];
	snprintf(str, sizeof(str), "%s:%d -> %s:%d",
			 localAddr_.ip().c_str(),
			 localAddr_.port(),
			 peerAddr_.ip().c_str(),
			 peerAddr_.port());
	return std::string(str);
}


void TcpConnection::setConnectionCallback(TcpConnectionCallback cb)
{
THE_INFO_OF_RUN;
	onConnectionCb_ = cb;
}

void TcpConnection::setMessageCallback(TcpConnectionCallback cb)
{
THE_INFO_OF_RUN;
	onMessageCb_ = cb;
}

void TcpConnection::setCloseCallback(TcpConnectionCallback cb)
{
THE_INFO_OF_RUN;
	onCloseCb_ = cb;
}

void TcpConnection::handleConnectionCallback()
{
THE_INFO_OF_RUN;
	if(onConnectionCb_)
		onConnectionCb_(shared_from_this());
}

void TcpConnection::handleMessageCallback()
{
THE_INFO_OF_RUN;
	if(onMessageCb_)
		onMessageCb_(shared_from_this());
}

void TcpConnection::handleCloseCallback()
{
THE_INFO_OF_RUN;
	if(onCloseCb_)
		onCloseCb_(shared_from_this());
}

}// end of namespace wd
