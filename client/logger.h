#pragma once


#include <string>


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
    static bool init(bool enable, std::string &errmsg);

    static void log();
private:
    Logger();

private:
    static Logger *instance_;
    static int client_sock;
};

};
