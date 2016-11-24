#include "Socket.h"
#include "TcpConnection.h"
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <iostream>

#include <iostream>
using std::cout;
using std::endl;
#define THE_INFO_OF_RUN (std::cout<<"    FILE:"<<__FILE__<<"    function:"<<__func__<<"    LINE:"<<__LINE__<<endl)
int main(int argc, char const *argv[])
{
	THE_INFO_OF_RUN;
    int fd = ::socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
    if(fd == -1)
    {
        perror("create socket error");
        exit(EXIT_FAILURE);
    }

	wd::InetAddress addr("192.168.1.122", 9999);

	wd::Socket sock(fd);
	sock.ready(addr);

    int peerfd = sock.accept();

	wd::TcpConnectionPtr conn(new wd::TcpConnection(peerfd));

    std::cout<<conn->toString()<<"has connection"<<std::endl;
    while(1)
    {
        std::string msg(conn->receive());
		std::cout << msg << std::endl;
        conn->send(msg);
    }

    conn->shutdown();
    close(fd);

    return 0;
}
