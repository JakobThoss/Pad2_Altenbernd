#ifndef GRAPHOBJ_H
#define GRAPHOBJ_H
#include "ort.h"
#include <math.h>


class GraphObj {
public:
    GraphObj(const Ort &einOrt) // allg. Konstruktor
        : Referenzkoordinaten(einOrt) {
        cout << "GraphObjKonstruktor " << endl;
    }

    // Bezugspunkt ermitteln
    const Ort& Bezugspunkt() const {
        return Referenzkoordinaten;
    }

    // alten Bezugspunkt ermitteln und
    // gleichzeitig neuen wählen
    Ort Bezugspunkt(const Ort &nO) {
        Ort temp = Referenzkoordinaten;
        Referenzkoordinaten = nO;
        return temp;
    }
    // Koordinatenabfrage
    int X() const { return Referenzkoordinaten.X(); }
    int Y() const { return Referenzkoordinaten.Y(); }

    virtual double Flaeche() const {
        return 0;
    }
    virtual double Umfang() const {
        return 0;
    }


protected:
    Ort Referenzkoordinaten;
};
/* Die Entfernung zwischen 2 GraphObj-Objekten ist hier als
Entfernung ihrer Bezugspunkte (überladene Funktion) definiert.
*/
double Entfernung(const GraphObj &g1, const GraphObj &g2) {
    return Entfernung(g1.Bezugspunkt(), g2.Bezugspunkt());
}

#endif // GRAPHOBJ_H
