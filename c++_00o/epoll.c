
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

	// ����epollʵ��
	//int epollfd = epoll_create(EVENT_MAX);
	int epollfd = epoll_create1();
	if (epollfd == -1) {
		ERR_EXIT("epoll_create");
	}

	// �����Ҫ�������ļ�������
	struct epoll_event ev;
	ev.data.fd = listenfd;
	ev.events = EPOLLIN;
	ret = epoll_ctl(epollfd, EPOLL_CTL_ADD, listenfd, &ev);
	if (ret == -1) {
		ERR_EXIT("epoll_ctl");
	}
	
	
	// ִ���¼�ѭ��
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
			//��������ӵĴ���
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

				//���������ӵ�ʱ����һ������
				//fprintf(stdout, "IP = %s, port = %d\n",
				//		inet_ntoa(peeraddr.sin_addr), ntohs(peeraddr.sin_port));
        //����һ���������������ƻ��Ĳ���
        onConnection();
			} else {
				//��Ծ����ӵĴ���
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
						//ɾ��������
						struct epoll_event ev;
						ev.data.fd = peerfd;
						
						//���ӶϿ���ʱ����һ������
						//....do something
						onCloseCb();
						

						ret = epoll_ctl(epollfd, EPOLL_CTL_DEL, peerfd, &ev);
						if (ret == -1) {
							ERR_EXIT("epoll_ctl");
						}
						continue;
					}
					fprintf(stdout, "receive: %s", recvbuf);
					
					//�������ݵĹ���
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
