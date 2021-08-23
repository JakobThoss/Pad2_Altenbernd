#ifndef FLUG_H
#define FLUG_H
#include "passagier.h"
#include <fstream>

class Flug
{
private:
    vector<Passagier> passagier_vec;
    int maxAnzahlPlaetze;
    int gebuchteplaetze;

    string abflug;
    string ziel;

    int flugnummer;
    static int counter;


public:
    Flug();
    Flug(const string & p_abflug, const string & p_ziel, int p_maxAnzahlPlaetze);
    Flug(int p_flugnummer, const string & p_abflug, const string & p_ziel, int Maxanzahl_plaetze);

    void menue();
    void eingabe();
    void buchen();
    void stornieren();
    void ausgabe();
    void data_read();
    void data_write();


    int getFlugnummer() const;
    string getAbflug() const;
    static void setCounter(int value);
    string getZiel() const;
    int getMaxAnzahlPlaetze() const;
    int getGebuchteplaetze() const;
};

#endif // FLUG_H
