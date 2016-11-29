 ///
 /// @file    _SocketIO.cc
 /// @author  ToTYToT(hongzimeng@foxmail.com)
 /// @date    2016-11-25 09:53:57
 ///
#include "_THE_INFO_OF_RUN.h"
#include "_SocketIO.h"
#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include <errno.h>
#include <sys/types.h>
#include <sys/socket.h>
namespace T520
{
SocketIO::SocketIO(int sockfd)
:_sockfd(sockfd)
{
	THE_INFO_OF_RUN;
}
size_t SocketIO::readn(char*buf,size_t count)
{
	THE_INFO_OF_RUN;
	size_t nleft=count;
	char *pbuf=buf;
	while(nleft>0)
	{
		int nread=::read(_sockfd,pbuf,nleft);
		if(-1==nread)
		{
			if(EINTR==errno)
				continue;
			return EXIT_FAILURE;
		}
		else if(0==nread)
		{
			break;
		}
		pbuf+=nread;
		nleft-=nread;
	}
	return (count-nleft);
}
size_t SocketIO::writen(const char *buf,size_t count)
{
	THE_INFO_OF_RUN;
	size_t nleft=count;
	const char*pbuf=buf;
	while(nleft>0)
	{
		int nwrite=::write(_sockfd,pbuf,nleft);
		if(-1==nwrite)
		{
			if(EINTR==errno)
				continue;
			return EXIT_FAILURE;
		}
		nleft-=nwrite;
		pbuf+=nwrite;
	}
	return (count-nleft);
}
size_t SocketIO::recv_peek(char*buf,size_t count)
{
	THE_INFO_OF_RUN;
	int nread;
	do
	{
		nread=::recv(_sockfd,buf,count,MSG_PEEK);
	}while(-1==nread&&EINTR==errno);
	return nread;
}
size_t SocketIO::readline(char* buf,size_t maxlen)
{
	THE_INFO_OF_RUN;
	size_t nleft=maxlen-1;
	char*pbuf=buf;
	size_t total=0;
	while(nleft>0)
	{
		int nread=recv_peek(pbuf,nleft);
		if(nread<=0)
			return nread;
		for(size_t idx=0;idx!=nread;++idx)
		{
			if(pbuf[idx]=='\n')
			{
				size_t nsize=idx+1;
				if(readn(pbuf,nsize)!=nsize)
					return EXIT_FAILURE;
				pbuf+=nsize;
				total+=nsize;
				*pbuf=0;
				return total;
			}
		}
		if(readn(pbuf,nread)!=nread)
			return EXIT_FAILURE;
		pbuf+=nread;
		nleft-=nread;
		total+=nread;
	}
	*pbuf=0;
	return maxlen-1;
}
}
