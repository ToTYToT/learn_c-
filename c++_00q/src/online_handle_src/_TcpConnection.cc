 ///
 /// @file    _TcpConnetion.cc
 /// @author  ToTYToT(hongzimeng@foxmail.com)
 /// @date    2016-11-26 09:25:20
 ///
#include "_TcpConnection.h"
#include "_EpollPoller.h"
#include <string.h>
#include <stdio.h>
#include "_THE_INFO_OF_RUN.h"
namespace T520
{
TcpConnection::TcpConnection(int sockfd,EpollPoller * loop)
:_sockfd(sockfd)
,_sockIO(sockfd)
,_localAddr(T520::Socket::getLocalAddr(sockfd))
,_peerAddr(T520::Socket::getPeerAddr(sockfd))
,_isShutdownWrite(false)
,_loop(loop)
{
	THE_INFO_OF_RUN;
}
TcpConnection::~TcpConnection()
{
	THE_INFO_OF_RUN;
	if(!_isShutdownWrite)
	{
		_isShutdownWrite=true;
		shutdown();
	}
}
std::string TcpConnection::receive()
{
	THE_INFO_OF_RUN;char buf[1024];
	memset(buf,0,sizeof(buf));
	size_t ret = _sockIO.readline(buf,sizeof(buf));
	if(ret==0)
	{
		return std::string();
	}
	else
		return std::string(buf);
}
void TcpConnection::send(const std::string &msg)
{
	THE_INFO_OF_RUN;
	_sockIO.writen(msg.c_str(),msg.size());
}
void TcpConnection::sendAndClose(const std::string & msg)
{
	THE_INFO_OF_RUN;
	send(msg);
	shutdown();
}
void TcpConnection::sendInLoop(const std::string & msg)
{
	THE_INFO_OF_RUN;
	_loop->runInLoop(std::bind(&TcpConnection::send,this,msg));
}
void TcpConnection::shutdown()
{
	THE_INFO_OF_RUN;
	if(!_isShutdownWrite)
		_sockfd.shutdownWrite();
	_isShutdownWrite=true;
}
std::string TcpConnection::toString()
{
	THE_INFO_OF_RUN;
	char str[100];
	snprintf(str,sizeof(str),"%s:%d ->%s:%d",_localAddr.ip().c_str(),_localAddr.port(),_peerAddr.ip().c_str(),_peerAddr.port());
	return std::string(str);
}
void TcpConnection::setConnectionCallback(TcpConnectionCallback cb)
{
	THE_INFO_OF_RUN;
	_onConnectionCb=cb;
}
void TcpConnection::setMessageCallback(TcpConnectionCallback cb)
{
	THE_INFO_OF_RUN;
	_onMessageCb=cb;
}
void TcpConnection::setCloseCallback(TcpConnectionCallback cb)
{
	THE_INFO_OF_RUN;
	_onCloseCb=cb;
}
void TcpConnection::handleConnectionCallback()
{
	THE_INFO_OF_RUN;
	if(_onConnectionCb)
		_onConnectionCb(shared_from_this());
}
void TcpConnection::handleMessageCallback()
{
	THE_INFO_OF_RUN;
	if(_onMessageCb)
		_onMessageCb(shared_from_this());
}
void TcpConnection::handleCloseCallback()
{
	THE_INFO_OF_RUN;
	if(_onCloseCb)
		_onCloseCb(shared_from_this());
}
}
