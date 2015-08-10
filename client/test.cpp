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
    LilyLog::Logger::init(true);

    LilyLog::Logger::log("Hello World");

    return 0;
}
