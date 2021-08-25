#ifndef QUEUE_H
#define QUEUE_H
#include <iostream>
#include <stack>

using namespace std;


class Queue
{
private:
    stack <int> S;
public:
    // Create , Enq , Deq, Front , Empty

    Queue() {
    }

    bool empty() {
        if(S.empty()){
            return true;
        } else {
            return false;
        }
    }

    void enq(int p_wert) {
        S.push(p_wert);
    }

    void deq() {
        stack <int> temp;

        while(!S.empty()) {
            int tmp = S.top();
            S.pop();
            temp.push(tmp);
        }

        temp.pop();

        while(!temp.empty()) {
            int tmp = temp.top();
            temp.pop();
            S.push(tmp);
        }
    }

    int front() {
        stack <int> temp;

        while(!S.empty()) {
            int tmp = S.top();
            S.pop();
            temp.push(tmp);
        }
        int ergebnis = temp.top();

        while(!temp.empty()) {
            int tmp = temp.top();
            temp.pop();
            S.push(tmp);
        }

        return ergebnis;
    }

};

#endif // QUEUE_H
