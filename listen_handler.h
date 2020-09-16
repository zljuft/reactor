#ifndef __LISTEN_HANDLER_H__
#define __LISTEN_HANDLER_H__
/*************************************************************************
    > File Name: listen_handler.h
    > Author: lifeng
    > Mail: zljuft@126.com 
    > Created Time: Tue 15 Sep 2020 03:21:50 PM CST
 ************************************************************************/

#include "event_handler.h"
#include "event.h"

class ListenHandler : public EventHandler
{
public:
    ListenHandler(Handle fd);
    virtual ~ListenHandler();
    virtual Handle get_handle() const
    {
        return _listen_fd;
    }

    virtual void handle_read();
    virtual void handle_write();
    virtual void handle_error();

private:
    Handle _listen_fd;
};



#endif
