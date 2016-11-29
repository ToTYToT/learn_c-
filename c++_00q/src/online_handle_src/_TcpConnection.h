 ///
 /// @file    _TcpConnetion.h
 /// @author  ToTYToT(hongzimeng@foxmail.com)
 /// @date    2016-11-25 23:25:08
 ///
#ifndef __T_TCPCONNCETION_H__ 
#define __T_TCPCONNCETION_H__
#include "_THE_INFO_OF_RUN.h"
#include "_Noncopyable.h"
#include "_InetAddress.h"
#include "_Socket.h"
#include "_SocketIO.h"
#include <string>
#include <memory>
#include <functional>
namespace T520
{
class EpollPoller;
class TcpConnection;
typedef std::shared_ptr<TcpConnection> TcpConnectionPtr;
class TcpConnection: Noncopyable,
	public std::enable_shared_from_this<TcpConnection>
{
public:
	typedef std::function<void(const TcpConnectionPtr&)> TcpConnectionCallback;
	TcpConnection(int sockfd,EpollPoller * loop);
	~TcpConnection();
	std::string receive();
	void send(const std::string &msg);
	void sendAndClose(const std::string & msg);
	void sendInLoop(const std::string & msg);
	void shutdown();
	std::string toString();
	void setConnectionCallback(TcpConnectionCallback cb);
	void setMessageCallback(TcpConnectionCallback cb);
	void setCloseCallback(TcpConnectionCallback cb);
	void handleConnectionCallback();
	void handleMessageCallback();
	void handleCloseCallback();
private:
	Socket _sockfd;
	SocketIO _sockIO;
	const InetAddress _localAddr;
	const InetAddress _peerAddr;
	bool _isShutdownWrite;
	EpollPoller * _loop;
	TcpConnectionCallback _onConnectionCb;
	TcpConnectionCallback _onMessageCb;
	TcpConnectionCallback _onCloseCb;
};
}
#endif
