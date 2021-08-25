#ifndef ORT_H
#define ORT_H
#include <iostream>
#include <string>
#include <vector>
#include <cmath>

using namespace std;

class Ort {

public:
    Ort(int einX = 0, int einY = 0) // Default: Nullpunkt
        : xKoordinate(einX), yKoordinate(einY) {
        cout << " Ort Konstrukor " << endl;
    }

    int X() const { return xKoordinate;}
    int Y() const { return yKoordinate;}

    void aendern(int x, int y) {
        xKoordinate = x;
        yKoordinate = y;
    }
private:
    int xKoordinate, yKoordinate;
};

// globale Funktionen
// Berechnung der Entfernung zwischen zwei Orten
double Entfernung(const Ort &Ort1, const Ort &Ort2) {
    double dx = static_cast<double>(Ort1.X() - Ort2.X());
    double dy = static_cast<double>(Ort1.Y() - Ort2.Y());
    return sqrt(dx*dx + dy*dy);
}
// Anzeige auf der Standardausgabe → später
void anzeigen(const Ort &O) {
    cout << '(' << O.X() << ", " << O.Y() << ')';
}

#endif // ORT_H


