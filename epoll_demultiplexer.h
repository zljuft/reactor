#ifndef __EPOLL_DEMULTIPLEXER_H__
#define __EPOLL_DEMULTIPLEXER_H__
/*************************************************************************
    > File Name: epoll_demultiplexer.h
    > Author: lifeng
    > Mail: zljuft@126.com 
    > Created Time: Tue 15 Sep 2020 02:49:30 PM CST
 ************************************************************************/

#include <map>
#include "event_handler.h"
#include "event.h"
#include "event_demultiplexer.h"

class EpollDemultiplexer: public EventDemultiplexer
{
public:
    EpollDemultiplexer();
    virtual ~EpollDemultiplexer();
    virtual int wait_event(std::map<Handle, EventHandler*>& handlers, int timeout = 0);
    virtual int regist(Handle handle, Event evt);
    virtual int remove(Handle handle);

private:
    int _max_fd;
    int _epoll_fd;
};

#endif
