#pragma once

#include<SDL2/SDL.h>
#include<SDL2/SDL_thread.h>

class Runnable {
public:
    virtual void run() = 0;
};

class Thread
{
public:
    enum Priority {
        LOW,
        NORMAL,
        HIGH
    };

public:
    virtual void setTarget(Runnable *r) = 0;
    virtual void setPriority(Priority p) = 0;
    virtual void start() = 0;
    virtual int join() = 0;
};
