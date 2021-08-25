#ifndef STACK_H
#define STACK_H
#include <vector>
#include <iostream>
#include <string>

using namespace std;


class Stack
{
private:
    int Atop;
    vector<double> S;

public:
    Stack() {
        Atop = -1;
    }

    bool Empty() {
        if(Atop == -1) {
            return true;
        } else {
            return false;
        }
    }

    void push(double wert) {
        S.push_back(wert);
        Atop++;
    }

    void pop() {
        if(Atop == -1){
            cerr << " Kein Element auf dem Stack " << endl;
        } else {
            S.pop_back();
            Atop--;
        }
    }

    double top() {
        if(Atop == -1){
            cerr << "Kein Element auf dem Stack " << endl;
        } else {
            return S[Atop];
        }
    }


};

#endif // STACK_H
