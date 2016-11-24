 ///
 /// @file    _EpollPoller.cc
 /// @author  ToTYToT(hongzimeng@foxmail.com)
 /// @date    2016-11-23 17:32:36
 ///
 
#include "_EpollPoller.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/epoll.h>
#include <unistd.h>
#include <errno.h>
#include <assert.h>

#include <iostream>
#define THE_INFO_OF_RUN (std::cout<<"                "<<__func__<<"    "<<__FILE__<<"-->"<<__LINE__<<std::endl)
using std::cout;
using std::endl;
namespace
{
int createEpollFd()
{
	int epollfd=::epoll_create1(0);
	if(epollfd==-1)
	{
		perror("create epoll fd error");
		exit(EXIT_FAILURE);
	}
	return epollfd;
}
void addEpollReadFd(int epollfd,int fd)
{
	struct epoll_event ev;
	ev.data.fd=fd;
	ev.events=EPOLLIN;
	if(epoll_ctl(epollfd,EPOLL_CTL_ADD,fd,&ev)==-1)
	{
		perror("add epoll fd error");
		exit(EXIT_FAILURE);
	}
}	
void delEpollReadFd(int epollfd,int fd)
{
	struct epoll_event ev;
	ev.data.fd=fd;
	if(epoll_ctl(epollfd,EPOLL_CTL_DEL,fd,&ev)==-1)
	{
		perror("del epoll fd error");
		exit(EXIT_FAILURE);
	}
}
int acceptConnFd(int listenfd)
{
	int peerfd=::accept(listenfd,NULL,NULL);
	if(peerfd==-1)
	{
		perror("accpet conn fd");
		exit(EXIT_FAILURE);
	}
	return peerfd;
}
ssize_t recvPeek(int sockfd,void *buf, size_t len)
{
	int nread;
	do
	{
		nread=::recv(sockfd,buf,len,MSG_PEEK);
	}
	while(nread==-1 && errno==EINTR);
	return nread;
}	
bool isConnectionClosed(int sockfd)
{
	char buf[1024];
	ssize_t nread=recvPeek(sockfd,buf,sizeof buf);
	if(nread==-1)
	{
		perror("recvPeek");
		exit(EXIT_FAILURE);
	}
	return (nread==0);
}
}

namespace wd
{
EpollPoller::EpollPoller(int listenfd)
:_epollfd(createEpollFd())
,_listenfd(listenfd)
,_events(1024)
	{
		addEpollReadFd(_epollfd,_listenfd);
	}
EpollPoller::~EpollPoller()
{
	::close(_epollfd);
}
void EpollPoller::waitEpollFd()
{
	int nready;
	do
	{
		nready=::epoll_wait(_epollfd,&*_events.begin(),static_cast<int>(_events.size()),5000);
	}while(nready==-1 && errno==EINTR);
	if(nready==-1)
	{
		perror("epoll wait error");
		exit(EXIT_FAILURE);
	}
	else if(nready==0)
	{
		printf("epoll timeout.\n");
	}
	else
	{
		if(nready==static_cast<int>(_events.size()*2));
		{
			_events.resize(_events.size()*2);
		}	
		for(int ix=0;ix!=nready;++ix)
		{
			if(_events[ix].data.fd==_listenfd)
			{
				if(_events[ix].events&EPOLLIN)
				handleConnection();
			}else
			{
				if(_events[ix].events&EPOLLIN)
					handleMessage(_events[ix].data.fd);
			}
		}
	}
}
void EpollPoller::handleConnection()
{
	int peerfd=acceptConnFd(_listenfd);
	addEpollReadFd(_epollfd,peerfd);
	std::pair<ConnectionList::iterator,bool> ret;
	TcpConnectionPtr conn(new TcpConnection(peerfd));
	conn->setConnectCallback(_onConnectCallback);
	conn->setMessageCallback(_onMessageCallback);
	conn->setCloseCallback(_onCloseCallback);
	ret=_lists.insert(std::make_pair(peerfd,conn));
	assert(ret.second==true);
	(void)ret;
	conn->handleConnectCallback();
}
void EpollPoller::handleMessage(int peerfd)
{
	bool isClosed=isConnectionClosed(peerfd);
	ConnectionList::iterator it=_lists.find(peerfd);
	assert(it!=_lists.end());
	if(isClosed)
	{
		it->second->handleCloseCallback();
		delEpollReadFd(_epollfd,peerfd);
		_lists.erase(it);
	}
	else
	{
		it->second->handleMessageCallback();
	}
}
void EpollPoller::loop()
{
	_isLooping=true;
	while(_isLooping)
	{
		waitEpollFd();
	}
	printf("Loop quit safely\n");
}
void EpollPoller::unloop()
{
	_isLooping=false;
}
}
