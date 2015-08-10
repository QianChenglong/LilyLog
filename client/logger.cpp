#include <errno.h>
#include <string.h>
#include <stdio.h>

#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#include "logger.h"

namespace LilyLog {

Logger *Logger::instance_ = NULL;
int Logger::client_sock_ = -1;
bool Logger::enable_ = false;
sockaddr_in Logger::server_addr_;


Logger *Logger::instance()
{
    if (Logger::instance_ != NULL) {
        return instance_;
    }

    Logger::init(false);

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

void Logger::init(bool enable)
{
    Logger::instance_ = new Logger();
    Logger::instance_->enable_ = enable;
    if (enable == false) {
        return;
    }

    client_sock_ = socket(AF_INET, SOCK_DGRAM, 0);
    if (client_sock_ == -1) {
        Logger::instance_->enable_ = false;
    }

    server_addr_.sin_family = AF_INET;
    server_addr_.sin_port = htons(LILYLOG_SERVER_PORT);
    server_addr_.sin_addr.s_addr = inet_addr(LILYLOG_SERVER_IP);
}

void Logger::log(const char *buf, const uint32_t len)
{
    if (enable_ == false) {
        return;
    }
    sendto(client_sock_, buf, len, 0, (sockaddr*)&server_addr_, sizeof(sockaddr));
}

void Logger::log(const std::string &msg)
{
    Logger::instance()->log(msg.c_str(), msg.size());
}

};
