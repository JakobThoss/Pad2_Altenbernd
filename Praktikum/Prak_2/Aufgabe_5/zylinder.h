#ifndef ZYLINDER_H
#define ZYLINDER_H
#include "geschenke.h"

class Zylinder : public Geschenke
{
private:
    int radius;
public:
    Zylinder(int p_umfang) {
        cout << "Konstruktor Zylinder " << endl;
        radius = p_umfang;
    }
    ~Zylinder() {
        cout << " Konstruktor " << endl;
    }
    virtual void einpacken() const {
        double oberflaeche = 2 * 3.14 * radius;
        cout << oberflaeche << endl;
    }

};

#endif // ZYLINDER_H
