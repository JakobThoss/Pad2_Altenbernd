#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main()

{
    ifstream quelle;
    string quellname = "/Users/jakobthoss/Pad2_Altenbernd/Vorlesung/Kapitel_1_3_MesswerteEinlesen/messwerte.txt";
    quelle.open(quellname.c_str(), ios::in);

    if(!quelle) {
        cerr << quellname << " kann nicht geoeffnet werden " << endl;
        exit(-1);
    }
    // Auslesen anzahl werte
    int anzahl;
    quelle >> anzahl;

    double wert[anzahl];

    //auslesen in Wert rein
    for(int i = 0; i < anzahl; i++){
        quelle >> wert[i];
    }

    // Summe
    double summe = 0;
    for(int i = 0; i < anzahl; i++){
        summe += wert[i];
    }

    // Mittelwert
    double mittelwert;
    mittelwert = summe / anzahl;

    //kleister wert
    double minimum = wert[0];
    for(int i = 1; i < anzahl; i++){
       if(wert[i] < minimum){
           minimum = wert[i];
       }
    }

    //groesster Wert
    double maximum = wert[0];
    for(int i = 1; i < anzahl; i++){
       if(wert[i] > maximum){
           maximum = wert[i];
       }
    }

    cout << endl << endl;
    cout << "Anzahl     : " << anzahl << endl;
    cout << "Summe      : " << summe << endl;
    cout << "Mittelwert : " << mittelwert << endl;
    cout << "MaxWert    : " << maximum << endl;
    cout << "MinWert    : " << minimum << endl;
    cout << endl << endl;

    quelle.close();

}


