#ifndef WD_SOCKET_H
#define WD_SOCKET_H

#include "Noncopyable.h"
#include "InetAddress.h"

namespace wd
{

class Socket : private Noncopyable
{
public:
    explicit Socket(int sockfd);
    Socket();
    ~Socket();

	void ready(const InetAddress & inetAddr);

    int fd() const { return sockfd_; }
	  void bindAddress(const InetAddress &addr);
    void listen();
    int accept();

    void shutdownWrite();

    void setReuseAddr(bool on);
    void setReusePort(bool on);


    //static
    static InetAddress getLocalAddr(int sockfd);
    static InetAddress getPeerAddr(int sockfd);

private:
    int sockfd_;
};

}//end namespace wd

#endif //WD_SOCKET_H
