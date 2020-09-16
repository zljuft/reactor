#ifndef __REACTOR_IMPL_H__
#define __REACTOR_IMPL_H__
/*************************************************************************
    > File Name: reactor_impl.h
    > Author: lifeng
    > Mail: zljuft@126.com 
    > Created Time: Tue 15 Sep 2020 02:24:35 PM CST
 ************************************************************************/

#include <map>
#include "event.h"
#include "event_handler.h"
#include "event_demultiplexer.h"

class ReactorImpl
{
public:
    ReactorImpl();
    ~ReactorImpl();
    int regist(EventHandler* handler, Event evt);
    void remove(EventHandler* handler);
    void dispatch(int timeout = 0);

private:
    EventDemultiplexer* _demultiplexer;
    std::map<Handle, EventHandler*> _handlers;
};


#endif
