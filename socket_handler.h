#ifndef __SOCKET_HANDLER_H__
#define __SOCKET_HANDLER_H__
/*************************************************************************
    > File Name: socket_handler.h
    > Author: lifeng
    > Mail: zljuft@126.com 
    > Created Time: Tue 15 Sep 2020 03:32:00 PM CST
 ************************************************************************/

#include "event_handler.h"
#include "event.h"

class SocketHandler : public EventHandler
{
public:
    SocketHandler(Handle fd);
    virtual ~SocketHandler();
    virtual Handle get_handle() const
    {
        return _socket_fd;
    }

    virtual void handle_read();
    virtual void handle_write();
    virtual void handle_error();

private:
    Handle _socket_fd;
    char* _buf;
    static const int MAX_SIZE = 1024;
};

#endif
