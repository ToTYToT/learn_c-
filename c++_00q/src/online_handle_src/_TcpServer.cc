 ///
 /// @file    _TcpServer.cc
 /// @author  ToTYToT(hongzimeng@foxmail.com)
 /// @date    2016-11-25 23:17:58
 ///
#include "_TcpServer.h" 
#include "_THE_INFO_OF_RUN.h"
namespace T520
{
TcpServer::TcpServer(unsigned short port)
:_inetAddr(port)
,_sockfd()
,_epollfd(_sockfd.fd())
{
	THE_INFO_OF_RUN;
	_sockfd.ready(_inetAddr);
}
TcpServer::TcpServer(const std::string & ip,unsigned short port) 
:_inetAddr(ip.c_str(),port)
,_sockfd()
,_epollfd(_sockfd.fd())
{
	THE_INFO_OF_RUN;
	_sockfd.ready(_inetAddr);
}
void TcpServer::start()
{
	THE_INFO_OF_RUN;
	_epollfd.loop();
}
void TcpServer::stop()
{
	THE_INFO_OF_RUN;
	_epollfd.unloop();
}
void TcpServer::setConnectionCallback(TcpServerCallback cb)
{
	THE_INFO_OF_RUN;
	_epollfd.setConnectionCallback(cb);
}
void TcpServer::setMessageCallback(TcpServerCallback cb)
{
	THE_INFO_OF_RUN;
	_epollfd.setMessageCallback(cb);
}
void TcpServer::setCloseCallback(TcpServerCallback cb)
{
	THE_INFO_OF_RUN;
	_epollfd.setCloseCallback(cb);
}
}
