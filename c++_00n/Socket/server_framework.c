/*********************************
 *@fileName: server.c
 *@author  : lemon
 *@email   : haohb13@gmail.com
 *@created : 2015-07-04 10:07:04
**********************************/

#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <errno.h>
#include <arpa/inet.h>
#include <netinet/in.h>


int test(void)
{
	int listenfd = socket(AF_INET, SOCK_STREAM, 0);
	if(listenfd == -1)
	{
		perror("socket");
		return EXIT_FAILURE;
	}
	
	

	int on = 1;
	if(setsockopt(listenfd, SOL_SOCKET, SO_REUSEADDR, &on, sizeof(on)) < 0)
	{//SO_REUSEPORT
		perror("setsockopt");
		close(listenfd);
		return EXIT_FAILURE;
	}

	struct sockaddr_in seraddr;
	memset(&seraddr, 0, sizeof(seraddr));
	seraddr.sin_family = AF_INET;
	seraddr.sin_port = htons(9999);
	seraddr.sin_addr.s_addr = inet_addr("192.168.175.130");
	if(bind(listenfd, (struct sockaddr*)&seraddr, sizeof(seraddr)) <0)
	{
		perror("bind");
		close(listenfd);
		return EXIT_FAILURE;
	}

	if(listen(listenfd, 10) < 0)
	{
		perror("listen");
		close(listenfd);
		return EXIT_FAILURE;
	}

	int peerfd = accept(listenfd, NULL, NULL);

	char buf[1024];
	memset(buf, 0, 1024);
	int nread = read(peerfd, buf, 1024);

	int nwrite = write(peerfd, buf, strlen(buf));

	return 0;

}


int main(void)
{
	InetAddress inetAddress("192.168.175.130", 8888);
	Socket socket;
#if 0
	socket.set_addr_reuse(true);
	socket.set_port_reuse(true);
	socket.bind(inetAddress);
	socket.listen();
#endif

	socket.ready();
	int peerfd = socket.accpet();


	SockeIO socketIo(peerfd);
	socketIo.readn(buf, size);
	socketIo.writn(buf, size);
}
