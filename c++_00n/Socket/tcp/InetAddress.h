#ifndef WD_INET_ADDRESS_H
#define WD_INET_ADDRESS_H

#include <string>
#include <netinet/in.h>

namespace wd
{

class InetAddress //copyable
{
public:
    explicit InetAddress(uint16_t port);
    InetAddress(const std::string &ip, uint16_t port);
    InetAddress(const struct sockaddr_in &addr);

    //set get
    void setSockAddrInet(const struct sockaddr_in &addr)
    { addr_ = addr; }
    const struct sockaddr_in *getSockAddrInet() const
    { return &addr_; }


    //ip port
    std::string toIp() const;
    uint16_t toPort() const;

private:
    struct sockaddr_in addr_;
};

}
#endif //WD_INET_ADDRESS_H