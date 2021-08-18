#ifndef STRECKE_H
#define STRECKE_H

#include "graphobj.h"

class Strecke : public GraphObj
{
public:
    Strecke(const Ort & start, const Ort & ende) : GraphObj(start), Endpunkt(ende) {
}
    double Laenge() const {
        return Entfernung(Endpunkt, this->Referenzkoordinaten);
    }
private:
    Ort Endpunkt;
};

#endif // STRECKE_H
