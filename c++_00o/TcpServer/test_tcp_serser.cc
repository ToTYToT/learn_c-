#include "TcpServer.h"
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#include <iostream>
#define THE_INFO_OF_RUN (std::cout<<"                "<<__func__<<"    "<<__FILE__<<"-->"<<__LINE__<<std::endl)
void onConnection(const wd::TcpConnectionPtr &conn)
{
		THE_INFO_OF_RUN;
    printf("%s\n", conn->toString().c_str());
    conn->send("hello, welcome to Chat Server.\r\n");
}

void onMessage(const wd::TcpConnectionPtr &conn)
{
		THE_INFO_OF_RUN;
    std::string s(conn->receive());
	printf("from client: %s\n", s.c_str());
    conn->send(s);
}

void onClose(const wd::TcpConnectionPtr &conn)
{
		THE_INFO_OF_RUN;
    printf("%s close\n", conn->toString().c_str());
}

int main(int argc, char const *argv[])
{
		THE_INFO_OF_RUN;
	wd::TcpServer server("192.168.1.122", 9999);
    server.setConnectCallback(&onConnection);
    server.setMessageCallback(&onMessage);
    server.setCloseCallback(&onClose);

    server.start();

    return 0;
}
