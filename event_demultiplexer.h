#ifndef __EVENT_DEMULTIPLEXER_H__
#define __EVENT_DEMULTIPLEXER_H__
/*************************************************************************
    > File Name: event_demultiplexer.h
    > Author: lifeng
    > Mail: zljuft@126.com 
    > Created Time: Tue 15 Sep 2020 02:45:01 PM CST
 ************************************************************************/

#include <map>
#include "event_handler.h"
#include "event.h"

class EventDemultiplexer
{
public:
    EventDemultiplexer(){};
    virtual ~EventDemultiplexer(){};
    virtual int wait_event(std::map<Handle, EventHandler*>& handlers, int timeout = 0) = 0;
    virtual int regist(Handle handle, Event evt) = 0;
    virtual int remove(Handle handle) = 0;
};

#endif
