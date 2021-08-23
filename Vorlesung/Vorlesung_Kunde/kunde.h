#ifndef KUNDE_H
#define KUNDE_H
#include <iostream>
#include <string>
#include <fstream>

using namespace std;

class Kunde
{
private:
    string name;
    int nummer;
public:
    Kunde();
    Kunde(const string & p_name, int p_nummer) {
        name = p_name;
        nummer = p_nummer;
    }
    void ausgabe();
    void data_write(ofstream & ausgabe);
    void data_read(ifstream & eingabe);

    string getName() const;
    int getNummer() const;
};

#endif // KUNDE_H
