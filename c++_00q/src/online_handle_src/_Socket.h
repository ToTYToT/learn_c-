 ///
 /// @file    _Socket.h
 /// @author  ToTYToT(hongzimeng@foxmail.com)
 /// @date    2016-11-25 09:48:42
 ///
#ifndef __T_SOCKET_H__
#define __T_SOCKET_H__
#include "_THE_INFO_OF_RUN.h"
#include "_Noncopyable.h"
namespace T520
{
class InetAddress;
class Socket: Noncopyable
{
public:
	Socket(int sockfd);
	Socket();
	~Socket();
	void ready(const InetAddress &addr);
	int accept();
	void shutdownWrite();
	int fd()
	{
		THE_INFO_OF_RUN;
		return _sockfd;
	}
	static InetAddress getLocalAddr(int sockfd);
	static InetAddress getPeerAddr(int sockfd);
private:
	void bindAddress(const InetAddress &addr);
	void listen();
	void setReuseAddr(bool flag);
	void setReusePort(bool flag);
	int _sockfd;
};
}
#endif
