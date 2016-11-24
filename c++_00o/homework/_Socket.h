 ///
 /// @file    _Socket.h
 /// @author  ToTYToT(hongzimeng@foxmail.com)
 /// @date    2016-11-23 21:51:48
 ///
 
#ifndef SOCKET_H_
#define SOCKET_H_

#include "_Noncopyable.h"
#include "_InetAddress.h"
#include <iostream>
#define THE_INFO_OF_RUN (std::cout<<"                "<<__func__<<"    "<<__FILE__<<"-->"<<__LINE__<<std::endl)
using std::cout;
using std::endl;
namespace wd
{
	class Socket : Noncopyable
	{
		public:
			explicit Socket(int sockfd);
			~Socket();
			int fd() const {return _sockfd;}
			void bindAddress(const InetAddress &addr);
			void listen();
			int accept();
			void shutdownWrite();
			void setTcpNoDelay(bool on);
			void setReuseAddr(bool on);
			void setReusePort(bool on);
			void setKeepAlive(bool on);
			static InetAddress getLocalAddr(int sockfd);
			static InetAddress getPeerAddr(int sockfd);
		private:
			const int _sockfd;
	};
}
#endif
