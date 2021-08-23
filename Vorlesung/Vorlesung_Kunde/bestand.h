#ifndef BESTAND_H
#define BESTAND_H
#include <vector>
#include "kunde.h"
#include "fstream"


class Bestand
{
private:
    vector<Kunde> kunden_vec;
    int anzahl_kunden;
public:
    Bestand();

    void menue();
    void data_read();
    void data_write();
    void addKunde(const string & p_name, int p_nummer);
    void kunde_hinzufuegen();
    void ausgabe();
};

#endif // BESTAND_H
