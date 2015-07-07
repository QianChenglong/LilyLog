#include <errno.h>
#include <string.h>
#include <stdio.h>

#include <iostream>

#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#include "logger.h"

namespace LilyLog {

Logger *Logger::instance_ = NULL;
int Logger::client_sock = -1;


Logger *Logger::instance()
{
    if (Logger::instance_ != NULL) {
        return instance_;
    }

    std::string errmsg;
    Logger::init(false, errmsg);

    return Logger::instance_;
}

Logger::Logger()
{

}

std::string addr_str(struct sockaddr_in &addr)
{
    char buf[128] = {0};
    sprintf(buf, "%s:%d", inet_ntoa(addr.sin_addr), ntohs(addr.sin_port));

    return buf;
}

bool Logger::init(bool enable, std::string &errmsg)
{
    if (Logger::instance_ != NULL) {
        return true;
    }

    Logger::instance_ = new Logger();

    // 创建套接字
    client_sock = socket(AF_INET, SOCK_STREAM, 0);
    if (client_sock == -1) {
        errmsg = std::string("create socket error:") + strerror(errno);
        return false;
    }

    // 服务器地址
    struct sockaddr_in server_addr;
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(6969);
    server_addr.sin_addr.s_addr = inet_addr("127.0.0.1");

    // 连接服务器
    if (connect(client_sock, (sockaddr*)&server_addr, sizeof(server_addr)) == -1) {
        errmsg = "connect to [" + addr_str(server_addr) + "] fail:" + strerror(errno);
        return false;
    }
    std::cout << addr_str(server_addr) << std::endl;

    return true;
}

void Logger::log()
{
    char buf[] = "Hello world";
    send(client_sock, buf, sizeof(buf), 0);
}

};
