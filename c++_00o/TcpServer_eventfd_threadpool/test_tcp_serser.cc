

#include "THE_INFO_OF_RUN.h" 
#include "TcpServer.h"
#include "Threadpool.h"
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#include <string>
#include <functional>
using std::string;
using std::bind;

using namespace wd;

class MyServer
{
public:
	MyServer(const string & ip, 
			 unsigned short port, 
			 size_t threadNum, 
			 size_t bufSize);

	void start();

	void onConnection(const TcpConnectionPtr & conn)
	{
THE_INFO_OF_RUN;
		printf("%s\n", conn->toString().c_str());
		conn->send("hello, welcome to Chat Server.\r\n");
	}

	void onMessage(const TcpConnectionPtr & conn)
	{
THE_INFO_OF_RUN;
		std::string s(conn->receive());
		printf("from client: %s\n", s.c_str());

		_threadpool.addTask(std::bind(&MyServer::doTaskThread,
							this, conn, s));
	}

	void onClose(const TcpConnectionPtr & conn)
	{
THE_INFO_OF_RUN;
		printf("%s close\n", conn->toString().c_str());
	}

	void doTaskThread(const TcpConnectionPtr & conn, const string & msg)
	{
THE_INFO_OF_RUN;
		//string ret = doQuery(msg);
		conn->sendInLoop(msg);
	}
private:
	TcpServer _tcpServer;
	Threadpool _threadpool;
};


MyServer::MyServer(const string & ip, 
			 unsigned short port, 
			 size_t threadNum, 
			 size_t bufSize)
: _tcpServer(ip, port)
, _threadpool(threadNum, bufSize)
{
THE_INFO_OF_RUN;
	using namespace std::placeholders;
	_tcpServer.setConnectionCallback(
			std::bind(&MyServer::onConnection, this, _1));
	_tcpServer.setMessageCallback(
			bind(&MyServer::onMessage, this, _1));
	_tcpServer.setCloseCallback(
			bind(&MyServer::onClose, this, _1));
}

void MyServer::start()
{
THE_INFO_OF_RUN;
	_threadpool.start();
	_tcpServer.start();
	//_threadpool.start();
}

int main(void)
{
THE_INFO_OF_RUN;
	MyServer mySerever("192.168.1.122", 9999, 2, 4);
	mySerever.start();

	return 0;
}
