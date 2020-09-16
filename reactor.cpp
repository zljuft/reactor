/*************************************************************************
    > File Name: reactor.cpp
    > Author: lifeng
    > Mail: zljuft@126.com 
    > Created Time: Tue 15 Sep 2020 02:15:06 PM CST
 ************************************************************************/

#include "reactor.h"
#include <assert.h>
#include <new>

Reactor Reactor::_reactor;

Reactor& Reactor::get_instance()
{
    return _reactor;
}

Reactor::Reactor()
{
    _reactor_impl = new (std::nothrow)ReactorImpl();
    assert(_reactor_impl != nullptr);
}

Reactor::~Reactor()
{
    if(nullptr != _reactor_impl)
    {
        delete _reactor_impl;
        _reactor_impl = nullptr;
    }
}

int Reactor::regist(EventHandler* handler, Event evt)
{
    return _reactor_impl->regist(handler, evt);
}

void Reactor::remove(EventHandler* handler)
{
    return _reactor_impl->remove(handler);
}

void Reactor::dispatch(int timeout)
{
    return _reactor_impl->dispatch(timeout);
}
