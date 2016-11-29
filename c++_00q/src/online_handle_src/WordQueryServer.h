 ///
 /// @file    WordQueryServer.h
 /// @author  ToTYToT(hongzimeng@foxmail.com)
 /// @date    2016-11-25 16:25:38
 ///
#ifndef __T_WORDQUERYSERVER_H__
#define __T_WORDQUERYSERVER_H__
#include "_THE_INFO_OF_RUN.h"
namespace T520
{
class WordQueryServer
{
public:
    WordQueryServer(const string &filename);
    void start();
private:
    void onConnection(const TcpConnectionPtr & conn);
    void onMessage(const TcpConnectionPtr &conn);
    void onClose(const TcpConnectionPtr & conn);
    void doTaskThread(const TcpConnectionPtr &conn,const string &msg);
private:
    Configuration _conf;
    WordQuery _wordQuery;
    TcpServer _tcpServer;
    Threadpool _pool;
};
}
#endif
