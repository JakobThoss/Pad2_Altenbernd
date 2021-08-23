#ifndef PASSAGIER_H
#define PASSAGIER_H
#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Passagier {

private:
    int Buchungsnummer;
    static int counter;
    string name;
public:
    Passagier();
    Passagier(const string & p_name);
    Passagier(const string & p_name, int p_buchungsnummer);
    void eingabe();
    void ausgabe();

    int getBuchungsnummer() const;
    string getName() const;
    void setName(const string &value);
    void setBuchungsnummer(int value);
    static void setCounter(int value);
    static int getCounter();
};

#endif // PASSAGIER_H
