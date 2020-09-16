/*************************************************************************
    > File Name: client.cpp
    > Author: lifeng
    > Mail: zljuft@126.com 
    > Created Time: Tue 15 Sep 2020 04:06:02 PM CST
 ************************************************************************/

#include <sys/socket.h>
#include <arpa/inet.h>
#include <iostream>
#include <errno.h>
#include <unistd.h>
//#include "reactor.h"
//#include "event_handler.h"
//#include "listen_handler.h"
//#include "event.h"
#include <string.h>
int main()
{
    int socket_fd = -1;
    if((socket_fd = socket(AF_INET, SOCK_STREAM, 0)) < 0)
    {
        std::cerr << "socket error " << errno << std::endl;
        exit(-1);
    }

    struct sockaddr_in seraddr;
    seraddr.sin_family = AF_INET;
    seraddr.sin_port = htons(53031);
    seraddr.sin_addr.s_addr = inet_addr("127.0.0.1");

    if(connect(socket_fd, (struct sockaddr*)&seraddr, sizeof(seraddr)) < 0)
    {
        std::cerr << "connect error " << errno << std::endl;
        exit(-2);
    }

    char buf[64] = {0};
    strcpy(buf, "hello world");
    int n = write(socket_fd, buf, strlen(buf));

    char rbuf[64] = {0};
    n = read(socket_fd, rbuf, sizeof(buf));
    std::cout << "sent [" << buf << "] reply [" << rbuf << "]" << std::endl;
    if(0 < n)
    {
        std::cerr << "read error " << errno << std::endl;
        exit(-3);
    }
    close(socket_fd);
    return 0;
}
