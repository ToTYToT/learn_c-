 ///
 /// @file    TcpServer.cc
 /// @author  lemon(haohb13@gmail.com)
 /// @date    2015-11-07 10:23:57
 ///

#include "TcpServer.h"

#include "THE_INFO_OF_RUN.h" 
namespace wd
{

TcpServer::TcpServer(unsigned short port)
	: inetAddr_(port),
	  sockfd_(),
	  epollfd_(sockfd_.fd())
{
THE_INFO_OF_RUN;
	sockfd_.ready(inetAddr_);
}

TcpServer::TcpServer(const string & ip, unsigned short port)
: inetAddr_(ip.c_str(), port)
, sockfd_()
, epollfd_(sockfd_.fd())
{
THE_INFO_OF_RUN;
	sockfd_.ready(inetAddr_);
}

void TcpServer::start()
{
THE_INFO_OF_RUN;
	epollfd_.loop();
}

void TcpServer::stop()
{
THE_INFO_OF_RUN;
	epollfd_.unloop();
}

void TcpServer::setConnectionCallback(TcpServerCallback cb)
{
THE_INFO_OF_RUN;
	epollfd_.setConnectionCallback(cb);
}

void TcpServer::setMessageCallback(TcpServerCallback cb)
{
THE_INFO_OF_RUN;
	epollfd_.setMessageCallback(cb);
}

void TcpServer::setCloseCallback(TcpServerCallback cb)
{
THE_INFO_OF_RUN;
	epollfd_.setCloseCallback(cb);
}

}//end of namespace wd
