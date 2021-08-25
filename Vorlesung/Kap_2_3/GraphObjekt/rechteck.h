#ifndef RECHTECK_H
#define RECHTECK_H
#include "graphobj.h"


class Rechteck : public GraphObj // von GraphObj erben
{
public:
 Rechteck(const Ort &p1, int h, int b) // Konstruktor
 // Initialisierung des Subobjekts
 : GraphObj(p1),
   hoehe(h), breite(b) {
 }
 // leerer Code-Block

 double Flaeche() const
 {
 // int-Überlauf vermeiden
 return double(hoehe) * breite;
 }

 double Umfang() const {
     return (2* hoehe + 2* breite);
 }

private:
 int hoehe, breite;
};

#endif // RECHTECK_H
