 ///
 /// @file    _TcpServer.h
 /// @author  ToTYToT(hongzimeng@foxmail.com)
 /// @date    2016-11-25 23:12:56
 ///
#ifndef __T_TCPSERVER_H__ 
#define __T_TCPSERVER_H__
#include "_THE_INFO_OF_RUN.h"
#include "_InetAddress.h"
#include "_Socket.h"
#include "_EpollPoller.h"
#include <string>
namespace T520
{
class TcpServer
{
public:
	typedef TcpConnection::TcpConnectionCallback TcpServerCallback;
	TcpServer(unsigned short port);
	TcpServer(const std::string & ip, unsigned short port);
	void start();
	void stop();
	void setConnectionCallback(TcpServerCallback cb);
	void setMessageCallback(TcpServerCallback cb);
	void setCloseCallback(TcpServerCallback cb);
private:
	InetAddress _inetAddr;
	Socket _sockfd;
	EpollPoller _epollfd;
	TcpServerCallback _onConnectionCb;
	TcpServerCallback _onMessageCb;
	TcpServerCallback _onCloseCb;
};
}
#endif
