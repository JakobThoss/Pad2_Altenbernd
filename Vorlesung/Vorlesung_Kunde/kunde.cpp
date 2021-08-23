#include "kunde.h"

string Kunde::getName() const
{
    return name;
}

int Kunde::getNummer() const
{
    return nummer;
}

Kunde::Kunde()
{

}

void Kunde::data_write(ofstream & ausgabe) {


    ausgabe.write((char*) &nummer, sizeof (int));

    int anzahl_chars = this->name.size();





    ausgabe.write((char*) &anzahl_chars, sizeof (int));

    for(int i = 0; i < anzahl_chars; i++){
        ausgabe.write((char*) &name[i], sizeof (char));
    }

}

void Kunde::data_read(ifstream &eingabe) {

    int nummer_temp = 0;
    eingabe.read((char*) &nummer_temp, sizeof(int));


    nummer = nummer_temp;

    int anzahl_chars_temp;
    eingabe.read((char*) &anzahl_chars_temp, sizeof (int));


    string name_temp = "";

    for(int i = 0; i < anzahl_chars_temp; i++){
        char temp_char;
        eingabe.read((char*) &temp_char, sizeof (char));
        name_temp += temp_char;
    }
    name = name_temp;

}

void Kunde::ausgabe() {
    cout << "Name: " << name << " | Nummer: " << nummer << endl;
}

