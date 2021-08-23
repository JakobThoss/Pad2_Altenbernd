#ifndef GESCHENKE_H
#define GESCHENKE_H
#include <iostream>
#include <cmath>

using namespace std;


class Geschenke
{
protected:
    double preis;
public:
    Geschenke() {
        cout << " Geschenke Konstruktor " << endl;
    }
    ~Geschenke() {
        cout << " Geschenke Destruktor " << endl;
    }
    virtual void einpacken() const  = 0;
};

#endif // GESCHENKE_H
