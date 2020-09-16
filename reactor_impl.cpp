/*************************************************************************
    > File Name: reactor_impl.cpp
    > Author: lifeng
    > Mail: zljuft@126.com 
    > Created Time: Tue 15 Sep 2020 02:28:41 PM CST
 ************************************************************************/

#include "reactor_impl.h"
#include <new>
#include <assert.h>
#include "epoll_demultiplexer.h"

ReactorImpl::ReactorImpl()
{
    _demultiplexer = new (std::nothrow)EpollDemultiplexer();
    assert(nullptr != _demultiplexer);
}

ReactorImpl::~ReactorImpl()
{
    auto iter = _handlers.begin();
    for(; iter != _handlers.end(); ++iter)
    {
        delete iter->second;
    }

    if(nullptr != _demultiplexer)
    {
        delete _demultiplexer;
        _demultiplexer = nullptr;
    }
}

int ReactorImpl::regist(EventHandler* handler, Event evt)
{
    int handle = handler->get_handle();
    if(_handlers.find(handle) != _handlers.end())
    {
        _handlers.insert(std::make_pair(handle, handler));
    }

    return _demultiplexer->regist(handle, evt);
}

void ReactorImpl::remove(EventHandler* handler)
{
    int handle = handler->get_handle();
    _demultiplexer->remove(handle);

    auto iter = _handlers.find(handle);
    if(iter != _handlers.end())
    {
        delete iter->second;
        _handlers.erase(iter);
    }
}

void ReactorImpl::dispatch(int timeout)
{
    _demultiplexer->wait_event(_handlers, timeout);
}
