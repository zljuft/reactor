/*************************************************************************
    > File Name: server.cpp
    > Author: lifeng
    > Mail: zljuft@126.com 
    > Created Time: Tue 15 Sep 2020 03:52:58 PM CST
 ************************************************************************/

#include <sys/socket.h>
#include <arpa/inet.h>
#include <iostream>
#include <errno.h>
#include "reactor.h"
#include "event_handler.h"
#include "listen_handler.h"
#include "event.h"

int main()
{
    int listen_fd = -1;
    if((listen_fd = socket(AF_INET, SOCK_STREAM | SOCK_NONBLOCK, 0)) < 0)
    {
        std::cerr << "socket error " << errno << std::endl;
        exit(-1);
    }

    struct sockaddr_in seraddr;
    seraddr.sin_family = AF_INET;
    seraddr.sin_port = htons(53031);
    seraddr.sin_addr.s_addr = htonl(INADDR_ANY);

    if(bind(listen_fd, (struct sockaddr*)&seraddr, sizeof(seraddr)) < 0)
    {
        std::cerr << "bind error " << errno << std::endl;
        exit(-2);
    }

    if(listen(listen_fd, 5) < 5)
    {
        std::cerr << "listen error " << errno << std::endl;
        exit(-3);
    }

    Reactor& actor = Reactor::get_instance();
    EventHandler* handler = new ListenHandler(listen_fd);
    actor.regist(handler, ReadEvent);

    while(true)
    {
        actor.dispatch(100);
    }

    return 0;
}
