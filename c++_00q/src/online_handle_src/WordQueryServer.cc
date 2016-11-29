 ///
 /// @file    WordQueryServer.cc
 /// @author  ToTYToT(hongzimeng@foxmail.com)
 /// @date    2016-11-29 17:18:24
 ///
 
#include "_THE_INFO_OF_RUN.h"
#include "_TcpServer.h"
#include "_Threadpool.h"
namespace T520
{

WordQueryServer::WordQueryServer(const string &filename)
:_conf(filename)
,_wordQuery(_conf)
,_tcpServer()
,_pool()
//:_tcpServer(ip,port)
//,_threadpool(threadNum, bufSize)
{
	THE_INFO_OF_RUN;
	using namespace std::placeholders;
	_tcpServer.setConnectionCallback(std::bind(&WordQueryServer::onConnection,this,_1));
	_tcpServer.setMessageCallback(std::bind(&WordQueryServer::onMessage,this,_1));
	_tcpServer.setCloseCallback(std::bind(&WordQueryServer::onClose,this,_1));
}

void WordQueryServer::start()
{
	THE_INFO_OF_RUN;
	_pool.start();
	_tcpServer.start();
}

void onConnection(const TcpConnectionPtr & conn)
{
}

void onMessage(const TcpConnectionPtr & conn)
{
	_pool.addTask(std::bind(&WordQueryServer::doTaskThread,this, conn,s));
}

void onClose(const TcpConnectionPtr & conn)
{
}

void doTaskThread(const TcpConnectionPtr &conn,const string &msg)
{
}

}


int main(void)
{
	THE_INFO_OF_RUN;
	WordQueryServer myServer("../../conf/myconf.conf");
	myServer.start();
	return 0;
}
