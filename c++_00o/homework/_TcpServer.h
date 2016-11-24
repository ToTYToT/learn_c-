 ///
 /// @file    _TcpServer.h
 /// @author  ToTYToT(hongzimeng@foxmail.com)
 /// @date    2016-11-23 22:57:55
 ///
 
#ifndef TCP_SERVER_H
#define TCP_SERVER_H

#include "_Noncopyable.h"
#include "_EpollPoller.h"
#include "_Socket.h"
#include <string>

#include <iostream>
#define THE_INFO_OF_RUN (std::cout<<"                "<<__func__<<"    "<<__FILE__<<"-->"<<__LINE__<<std::endl)
using std::cout;
using std::endl;
namespace wd
{
	class TcpServer :Noncopyable
	{
		public:
			typedef EpollPoller::EpollCallback TcpServerCallback;
			TcpServer(const std::string &ip,unsigned short port);
			void start()
			{_poller.loop();}
			void setConnectCallback(TcpServerCallback cb)
			{ _poller.setConnectCallback(std::move(cb));}
			void setMessageCallback(TcpServerCallback cb)
			{ _poller.setMessageCallback(std::move(cb));}
			void setCloseCallback(TcpServerCallback cb)
			{ _poller.setCloseCallback(std::move(cb));}
		private:
			InetAddress _addr;
			Socket _sockfd;
			EpollPoller _poller;
	};
}
#endif
