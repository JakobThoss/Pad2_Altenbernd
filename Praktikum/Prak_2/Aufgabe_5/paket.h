#ifndef PAKET_H
#define PAKET_H
#include "geschenke.h"


class Paket : public Geschenke
{
private:
    int laenge;
    int breite;
    int hoehe;
public:
    Paket(int a, int b, int c) {
        cout << " Konstruktor Paket " << endl;
        laenge = a;
        breite = b;
        hoehe = c;
    }
    ~Paket() {
        cout << " Konstruktor Paket " << endl;
    }
   virtual void einpacken() const {
        int Oberflaeche = (2 * laenge * breite) + (2 * laenge * hoehe) + (2 * breite * hoehe);
        cout << Oberflaeche << endl;
    }
};

#endif // PAKET_H
