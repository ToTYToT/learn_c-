 ///
 /// @file    _EpollPoller.h
 /// @author  ToTYToT(hongzimeng@foxmail.com)
 /// @date    2016-11-23 20:52:45
 ///
 
#include "_Noncopyable.h"
#include <vector>
#include <map>
#include <sys/epoll.h>
#include "_TcpConnection.h"
#include <iostream>
#define THE_INFO_OF_RUN (std::cout<<"                "<<__func__<<"    "<<__FILE__<<"-->"<<__LINE__<<std::endl)
using std::cout;
using std::endl;
namespace wd
{
class EpollPoller: Noncopyable
	{
		public:
			typedef TcpConnection::TcpConnectionCallback EpollCallback;
			explicit EpollPoller(int listenfd);
			~EpollPoller();
			void loop();
			void unloop();
			void setConnectCallback(EpollCallback cb)
			{ _onConnectCallback=std::move(cb);}
			void setMessageCallback(EpollCallback cb)
			{ _onMessageCallback=std::move(cb);}
			void setCloseCallback(EpollCallback cb)
			{ _onCloseCallback=std::move(cb);}
		private:
			void waitEpollFd();
			void handleConnection();
			void handleMessage(int peerfd);

			const int _epollfd;
			const int _listenfd;
			bool _isLooping;
			typedef std::vector<struct epoll_event> EventList;
			EventList _events;
			typedef std::map<int, TcpConnectionPtr> ConnectionList;
			ConnectionList _lists;
			EpollCallback _onConnectCallback;
			EpollCallback _onMessageCallback;
			EpollCallback _onCloseCallback;
	};
}
