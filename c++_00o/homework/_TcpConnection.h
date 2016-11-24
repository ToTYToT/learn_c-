 ///
 /// @file    _TcpConnection.h
 /// @author  ToTYToT(hongzimeng@foxmail.com)
 /// @date    2016-11-23 22:42:29
 ///
 
#ifndef TCP_CONNECTION_H
#define TCP_CONNECTION_H
#include "_Noncopyable.h"
#include <memory>
#include <functional>
#include "_Socket.h"
#include "_SocketIO.h"
#include <iostream>
#define THE_INFO_OF_RUN (std::cout<<"                "<<__func__<<"    "<<__FILE__<<"-->"<<__LINE__<<std::endl)
using std::cout;
using std::endl;
namespace wd
{
	class TcpConnection;
	typedef std::shared_ptr<TcpConnection> TcpConnectionPtr;
	class TcpConnection: Noncopyable,public std::enable_shared_from_this<TcpConnection>
	{
		public:
			typedef std::function<void(const TcpConnectionPtr &)> TcpConnectionCallback;
			explicit TcpConnection(int sockfd);
			~TcpConnection();
			void setConnectCallback(TcpConnectionCallback cb)
			{_onConnectCallback=std::move(cb);}
			void setMessageCallback(TcpConnectionCallback cb)
			{ _onMessageCallback=std::move(cb);}
			void setCloseCallback(TcpConnectionCallback cb)
			{ _onCloseCallback=std::move(cb);}
			void handleConnectCallback();
			void handleMessageCallback();
			void handleCloseCallback();
			void shutdown()
			{ _sockfd.shutdownWrite();_isShutdownWrite=true;}
			ssize_t readn(char *buf,size_t count);
			ssize_t writen(const char *buf,size_t count);
			ssize_t readLine(char *usrbuf,size_t maxlen);
			std::string receive();
			void send(const std::string &s);
			const InetAddress &getLocalAddr() const
			{ return _localAddr;}
			const InetAddress &getPeerAddr() const
			{ return _peerAddr;}
			std::string toString() const;
		private:
			Socket _sockfd;
			SocketIO _sockIO;
			const InetAddress _localAddr;
			const InetAddress _peerAddr;
			bool _isShutdownWrite;
			TcpConnectionCallback _onConnectCallback;
			TcpConnectionCallback _onMessageCallback;
			TcpConnectionCallback _onCloseCallback;
	};
}
#endif
