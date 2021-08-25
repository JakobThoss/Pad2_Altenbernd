#ifndef KREIS_H
#define KREIS_H
#include "graphobj.h"

class Kreis : public GraphObj
{
private:
    int radius;
public:
    Kreis(const Ort &p1, int p_r) // Konstruktor
    // Initialisierung des Subobjekts
    : GraphObj(p1),
      radius(p_r) {
    }
    double umfang() const {
        return (2.0 * M_PI * radius);
    }
    double Flaeche() const {
        return (M_PI * (radius * radius));
    }
};

#endif // KREIS_H
