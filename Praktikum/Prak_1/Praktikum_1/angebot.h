#ifndef ANGEBOT_H
#define ANGEBOT_H
#include "flug.h"


class Angebot
{
private:
    int anzahlFluege;
    int maxAnzahlFluege;
    vector<Flug> flug_vec;

public:
    Angebot(int p_MaxanzahlFluege);
    void menue();
    void flug_buchen();
    void flug_waehlen();
    void ausgabe();
    void data_read();
    void data_write();
};

#endif // ANGEBOT_H
