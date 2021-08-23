#include "passagier.h"

int Passagier::counter = 1000;

int Passagier::getBuchungsnummer() const
{
    return Buchungsnummer;
}

string Passagier::getName() const
{
    return name;
}

void Passagier::setName(const string &value)
{
    name = value;
}

void Passagier::setBuchungsnummer(int value)
{
    Buchungsnummer = value;
}

void Passagier::setCounter(int value)
{
    counter = value;
}

int Passagier::getCounter()
{
    return counter;
}

Passagier::Passagier() : Buchungsnummer(counter++) {}

Passagier::Passagier(const string & p_name) : Buchungsnummer(counter++)
{
    this->name = p_name;
}

Passagier::Passagier(const string & p_name, int p_buchungsnummer) : Buchungsnummer(counter++) {
    this->name = p_name;
    this->Buchungsnummer = p_buchungsnummer;
}

void Passagier::eingabe(){

    cout << "Geben sie ihren Namen ein   ";
    string eingabe;
    cin >> eingabe;

    cout << endl;

    this->name = eingabe;

    if(!cin.good()){
        throw invalid_argument("Keine gültige Eingabe");
    }
}

void Passagier::ausgabe() {
    cout << "Name: " << this->name << " |  "  << "Nummer: " << this->Buchungsnummer << endl;
}
