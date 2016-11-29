 ///
 /// @file    _EpollPoller.cc
 /// @author  ToTYToT(hongzimeng@foxmail.com)
 /// @date    2016-11-24 22:11:02
 ///
#include "_THE_INFO_OF_RUN.h"
#include "_EpollPoller.h"
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <assert.h>
#include <sys/eventfd.h>
#define ERR_EXIT(m) \
    do { \
        perror(m);\
        exit(EXIT_FAILURE);\
    }while(0)
namespace T520
{
int createEpollFd()
{
	THE_INFO_OF_RUN;
	int efd=::epoll_create1(0);
	if(-1==efd)
	{
		ERR_EXIT("epoll_create1 error");
	}
	return efd;
}
int createEventfd()
{
	THE_INFO_OF_RUN;
	int evtfd=::eventfd(0,EFD_NONBLOCK|EFD_CLOEXEC);
	if(-1==evtfd)
	{
		ERR_EXIT("eventfd create error");
	}
	return evtfd;
}
void addEpollFdRead(int efd,int fd)
{
	THE_INFO_OF_RUN;
	struct epoll_event ev;
	ev.data.fd=fd;
	ev.events=EPOLLIN;
	int ret=epoll_ctl(efd,EPOLL_CTL_ADD,fd,&ev);
	if(-1==ret)
	{
		ERR_EXIT("epoll_ctl add error");
	}
}
void delEpollReadFd(int efd,int fd)
{
	THE_INFO_OF_RUN;
	struct epoll_event ev;
	ev.data.fd=fd;
	int ret=epoll_ctl(efd,EPOLL_CTL_DEL,fd,&ev);
	if(-1==ret)
	{
		ERR_EXIT("epoll_ctl del error");
	}
}
int acceptConnFd(int listenfd)
{
	THE_INFO_OF_RUN;
	int peerfd=::accept(listenfd,NULL,NULL);
	if(-1==peerfd)
	{
		ERR_EXIT("accept error");
	}
	return peerfd;
}
size_t recvPeek(int sockfd,void *buf,size_t len)
{
	THE_INFO_OF_RUN;
	int nread;
	do
	{
		nread=::recv(sockfd,buf,len,MSG_PEEK);
	}while(-1==nread&&EINTR==errno);
	return nread;
}
bool isConnectionClosed(int sockfd)
{
	THE_INFO_OF_RUN;
	char buf[1024];
	int nread=recvPeek(sockfd,buf,sizeof(buf));
	if(-1==nread)
	{
		perror("recvPeek---");
		return true;
	}
	return (0==nread);
}
EpollPoller::EpollPoller(int listenfd)
:_epollfd(createEpollFd())
,_listenfd(listenfd)
,_wakeupfd(createEpollFd())
,_isLooping(false)
,_eventsList(1024)
{
	THE_INFO_OF_RUN;
	addEpollFdRead(_epollfd,_listenfd);
	addEpollFdRead(_epollfd,_wakeupfd);
}
EpollPoller::~EpollPoller()
{
	THE_INFO_OF_RUN;
	::close(_epollfd);
}
void EpollPoller::loop()
{
	THE_INFO_OF_RUN;
	_isLooping=true;
	while(_isLooping)
	{
		waitEpollfd();
	}
}
void EpollPoller::unloop()
{
	THE_INFO_OF_RUN;
	if(_isLooping)
		_isLooping=false;
}
void EpollPoller::runInLoop(const Functor &cb)
{
	THE_INFO_OF_RUN;
	{
		MutexLockGuard mlg(_mutex);
		_pendingFunctors.push_back(cb);
	}
	wakeup();
}
void EpollPoller::doPendingFunctors()
{
	printf("doPendingFunctors()\n");
	std::vector<Functor> functors;
	{
		MutexLockGuard mlg(_mutex);
		functors.swap(_pendingFunctors);
	}
	for(size_t i=0;i<functors.size();++i)
	{
		functors[i]();
	}
}
void EpollPoller::wakeup()
{
	uint64_t one=1;
	ssize_t n=::write(_wakeupfd,&one,sizeof(one));
	if(n!=sizeof(one))
	{
		perror("EpollPoller::wakeup() n!=8");
	}
}
void EpollPoller::handleRead()
{
	uint64_t one=1;
	ssize_t n=::read(_wakeupfd,&one,sizeof(one));
	if(n!=sizeof(one))
	{
		perror("EpollPoller::handleRead() n!=8");
	}
}
void EpollPoller::setConnectionCallback(EpollCallback cb)
{
	_onConnectionCb=cb;
}
void EpollPoller::setMessageCallback(EpollCallback cb)
{
	_onMessageCb=cb;
}
void EpollPoller::setCloseCallback(EpollCallback cb)
{
	_onCloseCb=cb;
}
void EpollPoller::waitEpollfd()
{
	int nread;
	do
	{
		nread=::epoll_wait(_epollfd,&(*_eventsList.begin()),_eventsList.size(),5000);
	}while(-1==nread&&EINTR==errno);
	if(-1==nread)
	{
		ERR_EXIT("epoll_wait error");
	}
	else if(0==nread)
	{
		printf("epoll_wait timeout\n");
	}
	else
	{
		if(static_cast<int>(_eventsList.size())==nread)
		{
			_eventsList.resize(_eventsList.size()*2);
		}
		for(int idx=0; idx!=nread;++idx)
		{
			if(_eventsList[idx].data.fd==_listenfd)
			{
				if(_eventsList[idx].events &EPOLLIN)
				{
					handleConnection();
				}
			}
			else if(_eventsList[idx].data.fd==_wakeupfd)
			{
				printf("wakeup light\n");
				if(_eventsList[idx].events&EPOLLIN)
				{
					handleRead();
					doPendingFunctors();
				}
			}
			else
			{
				if(_eventsList[idx].events &EPOLLIN)
				{
					handleMessage(_eventsList[idx].data.fd);
				}
			}
		}
	}
}
void EpollPoller::handleConnection()
{
	int peerfd=acceptConnFd(_listenfd);
	addEpollFdRead(_epollfd,peerfd);
	TcpConnectionPtr conn(new TcpConnection(peerfd,this));
	conn->send("welcome to server.\n");
	conn->setConnectionCallback(_onConnectionCb);
	conn->setMessageCallback(_onMessageCb);
	conn->setCloseCallback(_onCloseCb);
	std::pair<ConnectionMap::iterator,bool> ret;
	ret=_connMap.insert(std::make_pair(peerfd,conn));
	assert(true==ret.second);
	(void)ret;
	conn->handleConnectionCallback();
}
void EpollPoller::handleMessage(int peerfd)
{
	bool isClosed=isConnectionClosed(peerfd);
	ConnectionMap::iterator it=_connMap.find(peerfd);
	assert(it!=_connMap.end());
	if(isClosed)
	{
		it->second->handleCloseCallback();
		delEpollReadFd(_epollfd,peerfd);
		_connMap.erase(it);
	}
	else
	{
		it->second->handleMessageCallback();
	}
}
}
