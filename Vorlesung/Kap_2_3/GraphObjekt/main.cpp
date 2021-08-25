#include "ort.h"
#include "graphobj.h"
#include "strecke.h"
#include "rechteck.h"
#include "kreis.h"



// Funktion zum Verschieben des Orts um dx und dy
Ort Ortsverschiebung(Ort derOrt, int dx, int dy) {

    derOrt.aendern(derOrt.X() + dx, derOrt.Y() + dy);

    return derOrt;
}



int main() {

    Rechteck R(Ort(0,0), 20 , 50);
    Strecke S(Ort(1,20), Ort(200,0));
    Kreis K(Ort(3,40), 3);

    GraphObj* GraphObjZeiger[] = { &R, &S, &K};

    int i = 0;
    while(GraphObjZeiger[i]){
        cout << "Flaeche: " << GraphObjZeiger[i++]->Flaeche() << endl;
    }

}
