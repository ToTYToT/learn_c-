
#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <sys/epoll.h>
#include <sys/signal.h>
#define EVENT_MAX 2048

int main(int argc, char **argv) {

	signal(SIGPIPE, SIG_IGN);
	int listenfd = socket(AF_INET, SOCK_STREAM, 0);
	if (listenfd < 0) {
		ERR_EXIT("socket");
	}

	int on = 1;
	if (setsockopt(listenfd, SOL_SOCKET, SO_REUSEADDR, &on, sizeof(on)) < 0)
		ERR_EXIT("setsockopt");

	struct sockaddr_in servaddr;
	servaddr.sin_family = AF_INET;
	servaddr.sin_port = htons(8989);
	servaddr.sin_addr.s_addr = htonl(INADDR_ANY);
	socklen_t len = sizeof servaddr;
	int ret = bind(listenfd, (struct sockaddr*) &servaddr, len);
	if (ret < 0) {
		ERR_EXIT("bind");
	}

	ret = listen(listenfd, SOMAXCONN);
	if (ret < 0) {
		ERR_EXIT("listen");
	}

	// 创建epoll实例
	//int epollfd = epoll_create(EVENT_MAX);
	int epollfd = epoll_create1();
	if (epollfd == -1) {
		ERR_EXIT("epoll_create");
	}

	// 添加需要监听的文件描述符
	struct epoll_event ev;
	ev.data.fd = listenfd;
	ev.events = EPOLLIN;
	ret = epoll_ctl(epollfd, EPOLL_CTL_ADD, listenfd, &ev);
	if (ret == -1) {
		ERR_EXIT("epoll_ctl");
	}
	
	
	// 执行事件循环
	struct epoll_event events[EVENT_MAX];
	int nready;
	while (1) {
    printf("here\n");
		//nready = poll(client, maxi + 1, -1);
		nready = epoll_wait(epollfd, events, EVENT_MAX, -1);
		if (nready == -1) {
			if (errno == EINTR) {
				continue;
			} else {
				ERR_EXIT("epoll");
			}
		}
		if (nready == 0) {
			continue;
		}

		int i;
		for (i = 0; i < nready; ++i) {
			//针对新连接的处理
			//if (client[0].revents & POLLIN) {
			if (events[i].data.fd == listenfd) {
				struct sockaddr_in peeraddr;
				bzero(&peeraddr, sizeof peeraddr);
				len = sizeof peeraddr;

				//accept
				int connfd = accept(listenfd, (struct sockaddr*) &peeraddr,
						&len);
				if (connfd == -1) {
					ERR_EXIT("accept");
				}

				struct epoll_event ev;
				ev.data.fd = connfd;
				ev.events = EPOLLIN;
				int ret = epoll_ctl(epollfd, EPOLL_CTL_ADD, connfd, &ev);
				if(ret == -1){
					ERR_EXIT("epoll add");
				}

				//建立新连接的时候做一个处理
				//fprintf(stdout, "IP = %s, port = %d\n",
				//		inet_ntoa(peeraddr.sin_addr), ntohs(peeraddr.sin_port));
        //设置一个函数对象，做定制化的操作
        onConnection();
			} else {
				//针对旧连接的处理
				int peerfd = events[i].data.fd;
				if (peerfd == -1) {
					continue;
				}
				//if (FD_ISSET(peerfd, &rset)) {
				if (events[i].events & POLLIN) {
					char recvbuf[MAXLINE + 1] = { 0 };
					int ret = readline(peerfd, recvbuf, MAXLINE);
					if (ret == -1) {
						ERR_EXIT("readline");
					}
					if (ret == 0) {
						fputs("client close\n", stdout);
						close(peerfd);
						//client[i].fd = -1;
						//删除旧连接
						struct epoll_event ev;
						ev.data.fd = peerfd;
						
						//连接断开的时候做一个处理
						//....do something
						onCloseCb();
						

						ret = epoll_ctl(epollfd, EPOLL_CTL_DEL, peerfd, &ev);
						if (ret == -1) {
							ERR_EXIT("epoll_ctl");
						}
						continue;
					}
					fprintf(stdout, "receive: %s", recvbuf);
					
					//处理数据的过程
					//writen(peerfd, recvbuf, strlen(recvbuf));
					onMessageCallback();

				}
			}

		}

	}

//	close(peerfd);
	close(listenfd);

	return 0;
}
