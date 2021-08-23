#include "bestand.h"

Bestand::Bestand()
{
    anzahl_kunden = 0;
}

void Bestand::menue() {

    bool running = true;

    do {

        cout << "---------------------- " << endl;
        cout << "(a) Kunden Hinzufuegen " << endl;
        cout << "(b) Kunden anzeigen    " << endl;
        cout << "(x) Beednen            " << endl;
        cout << "---------------------- " << endl;

        cout << "Eingabe: ";
        char temp;
        cin >> temp;
        cout << endl;

        printf("\033c");

        switch(temp) {
            case 'a': {
                kunde_hinzufuegen();
                break;
            }
            case 'b': {
                ausgabe();
                break;
            }
            case 'x': {
                running = false;
                break;
            }
            default : {
                cout << "Falsche eingabe " << endl;
            }

        }

    } while(running);
}
void Bestand::data_write() {

    string quellname = "/Users/jakobthoss/Pad2_Altenbernd/Vorlesung/Vorlesung_Kunde/build-Vorlesung_Kunde-Desktop_x86_darwin_generic_mach_o_64bit-Debug/kunden.bin";

    ofstream ausgabe;
    ausgabe.open(quellname.c_str(), ios::out | ios::binary);
    if(!ausgabe) {
        cout << "Datei kann nicht geoeffnet werden " << endl;
        exit(-2);
    }

 //   for(int j = 0; j < (int) kunden_vec.size(); j++){

   //     anzahl_kunden = anzahl_kunden+=1;
   // }

    anzahl_kunden = kunden_vec.size();
    ausgabe.write((char*) &anzahl_kunden, sizeof (int));

    for(int i = 0; i < (int) kunden_vec.size(); i++){
        kunden_vec[i].data_write(ausgabe);
    }
}

void Bestand::data_read() {

    string quellname = "/Users/jakobthoss/Pad2_Altenbernd/Vorlesung/Vorlesung_Kunde/build-Vorlesung_Kunde-Desktop_x86_darwin_generic_mach_o_64bit-Debug/kunden.bin";

    ifstream eingabe;
    eingabe.open(quellname.c_str(), ios::in | ios::binary);
    if(!eingabe) {
        cout << " Datei kann nicht geoeffnet werden " << endl;
        exit(-2);
    }


    eingabe.read((char*) &anzahl_kunden, sizeof (int));


    for(int i = 0; i < anzahl_kunden; i++){
        Kunde temp;
        temp.data_read(eingabe);
        kunden_vec.push_back(temp);

    }
}

void Bestand::addKunde(const string & p_name, int p_nummer) {

    /*cout << "Geben sie einen Namen an: ";
    string temp;
    cin >> temp;
    cout << endl;

    cout << "Geben sie eine Nummer an: ";
    int tmp;
    cin >> tmp;
    cout << endl;

    */
    Kunde temporaer(p_name,p_nummer);
    kunden_vec.push_back(temporaer);

}

void Bestand::kunde_hinzufuegen() {
    cout << "Geben sie einen Namen an: ";
    string temp;
    cin >> temp;

    cout << "Geben sie eine Nummer an: ";
    int tmp;
    cin >> tmp;
    cout << endl;


    Kunde temporaer(temp,tmp);
    kunden_vec.push_back(temporaer);
    printf("\033c");
}

void Bestand::ausgabe() {
    for(int i = 0; i < (int)kunden_vec.size(); i++){
        kunden_vec[i].ausgabe();
    }
}
