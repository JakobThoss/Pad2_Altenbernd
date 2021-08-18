#include "ort.h"
#include "graphobj.h"
#include "strecke.h"
#include "rechteck.h"



// Funktion zum Verschieben des Orts um dx und dy
Ort Ortsverschiebung(Ort derOrt, int dx, int dy) {

    derOrt.aendern(derOrt.X() + dx, derOrt.Y() + dy);

    return derOrt;
}

//Main für Ort
/*
 *
 *
int main() {

    // Main beim verschieben
    Ort einOrt(10, 300);
    Ort verschobenerOrt = Ortsverschiebung(einOrt, 10, -90);

    cout << " alter Ort: ";
    anzeigen(einOrt);

    cout << "\n neuer Ort: ";
    anzeigen(verschobenerOrt);

    cout << endl << endl;
}
*/

// Main GraphObjekt
/*
 *
 *
int main() {
    Ort Nullpunkt;
    GraphObj G0(Nullpunkt);

    Ort einOrt(10, 20);
    GraphObj G1(einOrt);

    // Ausgabe beider Bezugspunkte auf verschiedene Art:
    cout << "G0.X() = " << G0.X() << endl;
    cout << "G0.Y() = " << G0.Y() << endl;

    Ort R1 = G1.Bezugspunkt();

    cout << "R1.X() = " << R1.X() << endl;
    cout << "R1.Y() = " << R1.Y() << endl;

    // Ausgabe der Entfernung:
    cout << "Entfernung = " << Entfernung(G0, G1) << endl;
}

// Es gibt 2 Kosntruktor Aufrufe. 1) Ort Konstruktor , 2) GraphobjektKonstruktor
*/

int main() {
    // Definition zweier graphischer Objekte
    Ort Nullpunkt; // Default-Konstruktoraufruf
    GraphObj G0(Nullpunkt);
    Ort einOrt(10, 20);
    GraphObj G1(einOrt);
    Ort R1 = G1.Bezugspunkt();

    Ort O;
    Strecke S1(O, R1);

    cout << "Strecke von ";
    anzeigen(O);
    cout << " bis ";
    anzeigen(R1);
    cout << "\n Fläche der Strecke S1 = " << S1.Flaeche() << endl;
    cout << "Länge der Strecke S1 = " << S1.Laenge() << endl;

    einOrt = Ort(20, 30); // Neuzuweisung
    Ort O2(100, 50);

    Strecke S2(einOrt, O2);

    cout << "Entfernung der Bezugspunkte: " << Entfernung(S1.Bezugspunkt(), S2.Bezugspunkt()) << endl;
    cout << "Entfernung der Strecken S1, S2 = " << Entfernung(S1, S2) << endl;

    Rechteck R0(Ort(0,0), 20, 50);
    cout << "R0.Flaeche = " << R0.Flaeche() << endl;
    cout << R0.GraphObj::Flaeche();
}
