#ifndef __EVENT_HANDLER_H__
#define __EVENT_HANDLER_H__
/*************************************************************************
    > File Name: event_handler.h
    > Author: lifeng
    > Mail: zljuft@126.com 
    > Created Time: Tue 15 Sep 2020 03:16:56 PM CST
 ************************************************************************/

typedef int Handle;

class EventHandler
{
public:
    EventHandler(){}
    virtual ~EventHandler(){}
    virtual Handle get_handle() const = 0;
    virtual void handle_read() = 0;
    virtual void handle_write() = 0;
    virtual void handle_error() = 0;
};


#endif
