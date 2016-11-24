
#include "InetAddress.h"
#include "Socket.h"
#include "SocketIO.h"
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(int argc, char const *argv[])
{

	wd::InetAddress addr("192.168.1.122", 9999);
	wd::Socket sock;
	sock.ready(addr);

    int peerfd = sock.accept();

	wd::SocketIO sio(peerfd);
    char recvbuf[1024] = {0};
    while(1)
    {
		//memset(recvbuf,0,sizeof(recvbuf));
		sio.readline(recvbuf, sizeof(recvbuf));
        printf("receive msg : %s", recvbuf);
		sio.writen(recvbuf, strlen(recvbuf));
    }
        printf("receive msg s");
    return 0;
}
