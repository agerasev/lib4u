#ifndef MUTEX_HPP
#define MUTEX_HPP

class Mutex
{
public:
    virtual void lock() = 0;
    virtual void unlock() = 0;
    virtual void tryLock() = 0;
};

#endif // MUTEX_HPP
