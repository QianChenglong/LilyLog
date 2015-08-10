#pragma once


#include <string>

#include <netinet/in.h>


#define LILYLOG_SERVER_IP "127.0.0.1"
#define LILYLOG_SERVER_PORT 6969
namespace LilyLog {
// #define MakePrefix(fmt) std::string(__FUNCTION__).append("() : ").append(fmt).c_str()

// #define LOG_DEBUG(fmt, ...) {Logger::instance()->log()->debug(MakePrefix(fmt),  ##__VA_ARGS__);}
// #define LOG_DEBUG(fmt, ...) {Logger::instance()->log_->debug(MakePrefix(fmt),  ##__VA_ARGS__);}
// #define LOG_INFO(fmt, ...) {Logger::instance()->log_->info(MakePrefix(fmt),  ##__VA_ARGS__);}
// #define LOG_WARN(fmt, ...) {Logger::instance()->log_->warn(MakePrefix(fmt),  ##__VA_ARGS__);}
// #define LOG_ERROR(fmt, ...) {Logger::instance()->log_->error(MakePrefix(fmt),  ##__VA_ARGS__);}

class Logger {
public:
    static Logger* instance();
    static void init(bool enable);

    static void log(const char *buf, const uint32_t len);
    static void log(const std::string &msg);
private:
    Logger();

private:
    static Logger *instance_;
    static bool enable_;
    static int client_sock_;
    static sockaddr_in server_addr_;
};

};
