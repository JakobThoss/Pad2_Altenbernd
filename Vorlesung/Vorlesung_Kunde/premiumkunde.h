#ifndef PREMIUMKUNDE_H
#define PREMIUMKUNDE_H
#include "kunde.h"


class Premiumkunde : public Kunde
{
private:
    int umsatz;
public:
    Premiumkunde();
    Premiumkunde(int p_umsatz);
    virtual void ausgabe();

};

#endif // PREMIUMKUNDE_H
