#ifndef STACK_H
#define STACK_H
#include <iostream>

using namespace std;

template  <typename T, int maxSize>
class Stack
{
private:
    int Atop;
    T S[maxSize];
public:
    Stack() {
        Atop = -1;
    }

    void push(const T & x) {
        S[++Atop] = x;
    }

    void pop() {
        Atop--;
    }

    T top() {
        return S[Atop];
    }

    bool empty() const {
        return (Atop == -1);
    }

    void ausgabe() {
        for(int i = 0; i <= Atop; i++){
            cout << S[i] << " ";
        }
        cout << endl;
    }
};

#endif // STACK_H
