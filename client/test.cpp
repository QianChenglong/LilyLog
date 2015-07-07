#include <errno.h>
#include <string.h>
#include <stdio.h>

#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#include <iostream>

#include "logger.h"


int main(int argc,char* argv[])
{
    std::string errmsg;
    if (LilyLog::Logger::init(true, errmsg) == false) {
        std::cout << errmsg << std::endl;
        return -1;
    }

    LilyLog::Logger::log();

    return 0;
}
