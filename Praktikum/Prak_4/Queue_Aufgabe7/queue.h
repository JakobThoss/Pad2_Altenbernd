#ifndef QUEUE_H
#define QUEUE_H
#include <iostream>

using namespace std;

const int MaxStackSize = 4;

class Queue
{
private:
    int back;
    int front;
    double Q[MaxStackSize];
public:
    Queue() {
        front = -1;
        back = -1;
    }

    bool isFull() {
        if(front == 0 && back == MaxStackSize) {
            return true;
        }
        return false;
    }

    bool Empty() {
        if(front == back) {
            return true;
        }
        return false;
    }

    void Enq(int x) {
        if(isFull()) {
            cerr << "Overflow" << endl;
        } else {
            Q[back] = x;
            back++;
        }
    }

    void Deq() {
        if(front == back) {
            cerr << "underflow " << endl;
        } else {
            front++;
        }

    }

    double Front() {
        if(front == back) {
            cout << "Underflow " << endl;
        }
            if(front == MaxStackSize) {
                return Q[0];
            } else {
            return Q[front];
        }
    }

};

#endif // QUEUE_H
