/*************************************************************************
    > File Name: reactor.h
    > Author: lifeng
    > Mail: zljuft@126.com 
    > Created Time: Tue 15 Sep 2020 02:10:01 PM CST
 ************************************************************************/

#include "event_handler.h"
#include "event.h"
#include "reactor_impl.h"

class ReactorImpl;

class Reactor
{
public:
    static Reactor& get_instance();
    int regist(EventHandler* handler, Event evt);
    void remove(EventHandler* handler);
    void dispatch(int timeout = 0);

private:
    Reactor();
    ~Reactor();
    Reactor(const Reactor& reactor)=delete;
    Reactor& operator=(const Reactor& reactor)=delete;

    ReactorImpl* _reactor_impl;
    static Reactor _reactor;
};
