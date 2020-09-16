/*************************************************************************
    > File Name: listen_handler.cpp
    > Author: lifeng
    > Mail: zljuft@126.com 
    > Created Time: Tue 15 Sep 2020 03:25:05 PM CST
 ************************************************************************/

#include "listen_handler.h"
#include <unistd.h>
#include <sys/socket.h>
#include <stdio.h>
#include <new>
#include <assert.h>
#include "event_handler.h"
#include "reactor.h"
#include "socket_handler.h"

ListenHandler::ListenHandler(Handle fd)
    : _listen_fd(fd)
{

}

ListenHandler::~ListenHandler()
{
    close(_listen_fd);
}

void ListenHandler::handle_read()
{
    int fd = accept(_listen_fd, NULL, NULL);
    EventHandler* h = new(std::nothrow)SocketHandler(fd);
    assert(h != nullptr);

    Reactor& r = Reactor::get_instance();
    r.regist(h, ReadEvent);
}

void ListenHandler::handle_write()
{

}

void ListenHandler::handle_error()
{

}
