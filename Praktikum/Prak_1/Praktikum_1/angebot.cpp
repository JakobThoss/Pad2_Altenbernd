#include "angebot.h"

Angebot::Angebot(int p_maxAnzahlFluege)
{
    maxAnzahlFluege = p_maxAnzahlFluege;
}

void Angebot::menue() {
    bool running = true;

    //data_read();

    do {

        cout << " ------------------------------ " << endl;
        cout << " (a) Flug buchen                " << endl;
        cout << " (b) Flug waehlen               " << endl;
        cout << " (c) Anzeige aller Fluege       " << endl;
        cout << " (x) Beenden                    " << endl;
        cout << " ------------------------------ " << endl;

        cout << "Eingabe:  ";
        char eingabe;
        cin >> eingabe;
        printf("\033c");

        switch(eingabe) {
        case 'a':
            flug_buchen();
            break;

        case 'b':
            flug_waehlen();
            break;

        case 'c':
            ausgabe();
            break;

        case 'x':
            running = false;
            break;

        default:
            cout << "falsche eingabe " << endl;
            break;
        }


    } while (running);
    data_write();
}

void Angebot::flug_buchen() {
    anzahlFluege++;
    if(anzahlFluege > maxAnzahlFluege) {
        cout << " Es kann nicht noch ein Flug gebucht werden " << endl;
        anzahlFluege--;
        return;
    }
    Flug temp;
    temp.eingabe();
    flug_vec.push_back(temp);

}

void Angebot::flug_waehlen() {

    cout << "Geben sie die Flugnummer an: ";
    int temp;
    cin >> temp;

    bool gefunden = false;
    int index;

    for(int i = 0; i < anzahlFluege; i++){
        if(temp == flug_vec[i].getFlugnummer()){
            index = i;
            gefunden = true;
        }
    }
    if(gefunden == false){
        cout << "Flugnummer konnte nicht gefunden werden " << endl;
    } else {
        flug_vec[index].menue();
    }
}

void Angebot::ausgabe() {
    if(anzahlFluege <= 0){
        cout << " Es existiert noch kein Flug " << endl;
    } else {
        for(int i = 0; i < anzahlFluege; i++){
            cout << " Flugnummer : " << flug_vec[i].getFlugnummer();
            cout << " |  " << flug_vec[i].getAbflug() << " -> " << flug_vec[i].getZiel();
            cout << "    | " << flug_vec[i].getMaxAnzahlPlaetze() << " MAX Plaetze " << endl;
        }
    }
}

void Angebot::data_read() {

    string quellname = "./fluege.txt";

    ifstream lesen;
    lesen.open(quellname.c_str(), ios::in);

    if(!lesen) {
        cerr << quellname << " kann nicht geoffnet werden " << endl;
        exit(-1);
    }

    lesen >> anzahlFluege;

    if(anzahlFluege > maxAnzahlFluege){
        cout << " Zu viele Fluege " << endl;
    } else {

        lesen.get();



        string temp_abflug;
        string temp_ziel;
        int temp_flugnummer;
        int temp_MaxanzahlPlaetze;

        for(int i = 0; i < anzahlFluege; i++){
            lesen >> temp_flugnummer;
            lesen >> temp_MaxanzahlPlaetze;
            lesen >> temp_abflug;
            lesen >> temp_ziel;


            Flug temp(temp_flugnummer,temp_abflug, temp_ziel,temp_MaxanzahlPlaetze);
            flug_vec.push_back(temp);


        }

        Flug::setCounter(flug_vec[anzahlFluege-1].getFlugnummer()+1);
    }

    lesen.close();
}

void Angebot::data_write() {
    string quellname = "./fluege.txt";

    ofstream schreiben;
    schreiben.open(quellname.c_str(), ios::out);

    if(!schreiben) {
        cerr << quellname << " kann nicht geoeffnet werden " << endl;
        exit(-1);
    }

    schreiben << anzahlFluege << endl;

    for(int i = 0; i < anzahlFluege; i++){
        schreiben << flug_vec[i].getFlugnummer() << " " << flug_vec[i].getMaxAnzahlPlaetze() << " " << flug_vec[i].getAbflug() << " " << flug_vec[i].getZiel() << endl;
    }
    schreiben.close();
}
