 ///
 /// @file    _EpollPoller.h
 /// @author  ToTYToT(hongzimeng@foxmail.com)
 /// @date    2016-11-24 23:05:47
 ///
#ifndef __T_EPOLLPOLLER_H__
#define __T_EPOLLPOLLER_H__

#include "_THE_INFO_OF_RUN.h"
#include "_Noncopyable.h"
#include "_TcpConnection.h"
#include "_MutexLock.h"
#include <sys/epoll.h>
#include <vector>
#include <map>
#include <functional>
namespace T520
{
class EpollPoller: Noncopyable
{
public:
	typedef TcpConnection::TcpConnectionCallback EpollCallback;
	typedef std::function<void()> Functor;
	EpollPoller(int listenfd);
	~EpollPoller();
	void loop();
	void unloop();
	void runInLoop(const Functor & cb);
	void doPendingFunctors();
	void wakeup();
	void handleRead();
	void setConnectionCallback(EpollCallback cb);
	void setMessageCallback(EpollCallback cb);
	void setCloseCallback(EpollCallback cb);
private:
	void waitEpollfd();
	void handleConnection();
	void handleMessage(int peerfd);
	int _epollfd;
	int _listenfd;
	int _wakeupfd;
	bool _isLooping;
	MutexLock _mutex;
	std::vector<Functor> _pendingFunctors;
	typedef std::vector<struct epoll_event> EventList;
	EventList _eventsList;
	typedef std::map<int, TcpConnectionPtr> ConnectionMap;
	ConnectionMap _connMap;
	EpollCallback _onConnectionCb;
	EpollCallback _onMessageCb;
	EpollCallback _onCloseCb;
};
}
#endif
