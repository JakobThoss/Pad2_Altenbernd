#ifndef QUEUE_H
#define QUEUE_H
#include <iostream>
#include <deque>

using namespace std;

template  <typename T, int maxSize>
class Queue
{
private:
    deque <T> d;
public:
    Queue() {

    }

    bool empty() {
        return (d.empty());
    }

    void enq(T x) {
        d.push_back(x);
    }

    void deq() {
        d.pop_front();
    }

    T front() {
        return d.front();
    }

};

#endif // QUEUE_H
