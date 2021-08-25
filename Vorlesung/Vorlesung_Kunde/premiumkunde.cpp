#include "premiumkunde.h"

Premiumkunde::Premiumkunde()
{

}

Premiumkunde::Premiumkunde(int p_umsatz) {
    umsatz = p_umsatz;
}

void Premiumkunde::ausgabe() {
    cout << "Name: " << name << " | Nummer: " << nummer << " | Umsatz: " << umsatz << endl;
}
