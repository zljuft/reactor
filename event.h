/*************************************************************************
    > File Name: event.h
    > Author: lifeng
    > Mail: zljuft@126.com 
    > Created Time: Tue 15 Sep 2020 02:43:20 PM CST
 ************************************************************************/
#ifndef __EVENT_H__
#define __EVENT_H__
typedef unsigned int Event;
enum EventMask
{
    ReadEvent   = 0x01,
    WriteEvent  = 0x02,
    ErrorEvent  = 0x04,
    EventMask   = 0xff
};

#endif
