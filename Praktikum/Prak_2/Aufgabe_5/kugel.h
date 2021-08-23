#ifndef KUGEL_H
#define KUGEL_H
#include "geschenke.h"


class Kugel : public Geschenke
{
private:
    double radius;
public:
    Kugel(int p_radius) {
        cout << " Konstruktor Kugel " << endl;
        radius = p_radius;
    }
    ~Kugel() {
        cout << " Konstruktor Kugel " << endl;
    }
    virtual void einpacken() const {
        // Oberflaeche 4 * Pi * r^2

        double Oberflaeche = 4 * 3.14 * (radius * radius);
        cout << Oberflaeche;
    }
};

#endif // KUGEL_H
