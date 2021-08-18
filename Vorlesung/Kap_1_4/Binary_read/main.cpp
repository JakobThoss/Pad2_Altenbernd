#include <iostream>
#include <fstream>
using namespace std;

int main()
{

    int anzahl = 5;
    double werteArr[anzahl];
    werteArr[0] = 3.4;
    werteArr[1] = 1.4;
    werteArr[2] = 2.4;
    werteArr[3] = 4.4;
    werteArr[4] = 5.4;


    ofstream quelle;
    string quellname = "./werte.bin";
    quelle.open(quellname.c_str(), ios::out | ios::binary);

    if(!quelle){
        cerr << quellname << "Datei kann nicht geoeffnet werden " << endl;
        exit(-2);
    }

    quelle.write((char * ) &anzahl, sizeof(int));
    for(int i = 0; i < anzahl; i++){
        quelle.write((char * ) &werteArr[i], sizeof (double));
    }
    quelle.close();


    ifstream eingabe;
    eingabe.open(quellname.c_str(), ios::in | ios::binary);

    if(!quelle){
        cerr << quellname << "Datei kann nicht geoffnet werden " << endl;
    }

    int anzahlGelesen;
    eingabe.read((char * )&anzahlGelesen, sizeof (int));

    double neueWerteArr[anzahlGelesen];
    for(int j = 0; j < anzahlGelesen; j++){
        eingabe.read((char *)& neueWerteArr[j], sizeof (double));
    }
    eingabe.close();


    for(int j = 0; j < anzahlGelesen; j++){
        cout << neueWerteArr[j] << " ";
    }

    cout << endl << endl;



    return 0;
}
