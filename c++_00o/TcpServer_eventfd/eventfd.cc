 ///
 /// @file    eventfd.cc
 /// @author  lemon(haohb13@gmail.com)
 /// @date    2016-11-23 11:07:54
 ///
#include "THE_INFO_OF_RUN.h"
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <sys/eventfd.h>
#include <iostream>
using std::cout;
using std::endl;

#define handle_error(msg)\
	do{\
		perror(msg);\
		exit(EXIT_FAILURE);\
	}while(0)


int main(int argc, char ** argv)
{
	if(argc < 2){
		fprintf(stderr, "Usage %s <num> ...\n", argv[0]);
		exit(EXIT_FAILURE);
	}

	//设置evfd的初始值为10
	int evfd = eventfd(10, EFD_NONBLOCK|EFD_CLOEXEC);
	if(evfd == -1)
		handle_error("eventfd");

	uint64_t u;
	switch (fork()){
	case 0:
		{
			for(int i = 1; i < argc; ++i)
			{
				printf("Child writing %s to evfd\n", argv[i]);
				u = strtoull(argv[i], NULL, 0);
				int ret;
				THE_INFO_OF_RUN;
				THE_INFO_OF_RUN;
				THE_INFO_OF_RUN,
				ret = write(evfd, &u, sizeof(u));
				if(ret != sizeof(u)){
					handle_error("write");
				}
				//sleep(1);
				//sleep(8);
			}

			printf("Child has completed write");
				THE_INFO_OF_RUN,
			exit(EXIT_SUCCESS);
		}
	case -1:
		handle_error("fork");
		exit(0);
	default:
		{
			printf("Parent about to read!\n");
			for(int idx = 0; idx != 4; ++idx)
			{
		//	sleep(1);
			int ret;
			THE_INFO_OF_RUN;
			//sleep(5);
				THE_INFO_OF_RUN,
			ret = read(evfd, &u, sizeof(u));
			if(ret != sizeof(u)){
				THE_INFO_OF_RUN;
				handle_error("read");
			}
			printf("Parent read %llu from evfd\n",(unsigned long long) u);
			}
				THE_INFO_OF_RUN,
			exit(EXIT_SUCCESS);
		}
	}
}
