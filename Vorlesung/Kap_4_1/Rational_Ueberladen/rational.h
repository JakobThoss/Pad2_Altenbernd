#ifndef RATIONAL_H
#define RATIONAL_H
#include <iostream>

using namespace std;


class Rational
{
private:
    int zaehler;
    unsigned int nenner;
public:
    Rational() {
        zaehler = 0;
        nenner = 1;
    }

    Rational(int p_zaehler, unsigned int p_nenner) {
        zaehler = p_zaehler;
        nenner = p_nenner;
    }

    Rational(long l) {
        zaehler = l;
        nenner = 1;
    }
    int getZaehler() const {
        return zaehler;
    }
    unsigned int getNenner() const {
        return nenner;
    }

    bool operator<(const Rational& b) {
        double wert = (double) this->getZaehler() / this->getNenner();
        double wert2 = (double) b.getZaehler() / b.getNenner();
        return (wert < wert2);
    }
};

bool operator==(const Rational& a, const Rational& b) {
    return a.getZaehler() == b.getZaehler() && a.getNenner() == b.getNenner();
}

bool operator==(const Rational& a, int b) {
    double wert = (double) a.getZaehler() / a.getNenner();
    return (wert == b);
}



#endif // RATIONAL_H
