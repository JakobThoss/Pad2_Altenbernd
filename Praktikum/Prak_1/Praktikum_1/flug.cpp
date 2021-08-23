#include "flug.h"

int Flug::counter = 100;

int Flug::getFlugnummer() const
{
    return flugnummer;
}

string Flug::getAbflug() const
{
    return abflug;
}

void Flug::setCounter(int value)
{
    counter = value;
}

string Flug::getZiel() const
{
    return ziel;
}

int Flug::getMaxAnzahlPlaetze() const
{
    return maxAnzahlPlaetze;
}

int Flug::getGebuchteplaetze() const
{
    return gebuchteplaetze;
}

Flug::Flug() : flugnummer(counter++){

}

Flug::Flug(const string & p_abflug, const string & p_ziel, int p_maxAnzahlPlaetze) : flugnummer(counter++)
{
    abflug = p_abflug;
    ziel = p_ziel;
    maxAnzahlPlaetze = p_maxAnzahlPlaetze;
}
Flug::Flug(int p_flugnummer, const string & p_abflug, const string & p_ziel, int Maxanzahl_plaetze) : flugnummer(counter++){
    abflug = p_abflug;
    maxAnzahlPlaetze = p_flugnummer;
    ziel = p_ziel;
    maxAnzahlPlaetze = Maxanzahl_plaetze;
}

void Flug::menue() {

    this->data_read();

    bool running = true;

    do {
        cout << " Flug : " << this->flugnummer  << " (" << this->gebuchteplaetze << " / " << this-> maxAnzahlPlaetze << ") " <<  endl;
        cout << " --------------------------- " << endl;
        cout << " (a) Flug buchen             " << endl;
        cout << " (b) Flug stornieren         " << endl;
        cout << " (c) Anzeige aller Buchungen " << endl;
        cout << " (x) Beenden                 " << endl;
        cout << " --------------------------- " << endl;

        cout << "Eingabe:  ";
        char eingabe;
        cin >> eingabe;
        printf("\033c");

        switch(eingabe) {
        case 'a':
            this->buchen();
            break;

        case 'b':
            this->stornieren();
            break;

        case 'c':
            this->ausgabe();
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

void Flug::eingabe() {
    cout << " Geben sie ein Abflugsort ein ";
    string temp;
    cin >> temp;

    abflug = temp;

    cout << " Geben sie den Zielort ein ";
    string tmp;
    cin >> tmp;

    ziel = tmp;

    cout << " Geben sie die maximae Anzahl an Plaetzen an (0-10) ";
    int tempo;
    cin >> tempo;

    if(tempo >= 0 && tempo <= 10){
        maxAnzahlPlaetze = tempo;
    } else {
        cout << " so viele Plaetze gibt es in einem Flugzeug nicht " << endl;
    }
    printf("\033c");
}

void Flug::buchen() {
    if(gebuchteplaetze < maxAnzahlPlaetze){

        Passagier temp;
        temp.eingabe();
        passagier_vec.push_back(temp);
        gebuchteplaetze++;
    } else {
        cout << " keine freien Plaetze mehr " << endl;
    }
}

void Flug::stornieren() {
    if(gebuchteplaetze == 0){
        cout << " es existiert noch kein Passagier " << endl;
    } else {


        cout << "Geben sie die gewuenschte Nummer ein  ";
        int eingabe;
        cin >> eingabe;
        cout << endl;

        if(!cin.good()){
            throw invalid_argument(" keine gueltige Eingabe");
        } else {
            bool gefunden = false;
            for(int i = 0; i < gebuchteplaetze; i++){
                if( eingabe == passagier_vec[i].getBuchungsnummer() ){
                    passagier_vec.erase(passagier_vec.begin()+i);
                    gefunden = true;
                    gebuchteplaetze--;
                }
            }
            if(gefunden == false) {
                cout << "Buchungsnummer nicht gefunden " << endl;
            } else {
                cout << " geloescht ! " << endl;
            }
        }
    }
}

void Flug::ausgabe() {
    if(gebuchteplaetze <= 0){
        cout << "Es existiert noch kein Passagier in diesem Flug " << endl;
    } else {
        for(int i = 0; i < gebuchteplaetze; i++){
            passagier_vec[i].ausgabe();
        }
    }
    cout << maxAnzahlPlaetze - gebuchteplaetze << " freie Plaetze " << endl << endl;
}

void Flug::data_read() {

    string quellname = "./" + this->abflug + "flugplaetze.txt";

    ifstream lesen;
    lesen.open(quellname.c_str(), ios::in);

    if(!lesen) {
        cerr << quellname << " kann nicht geoffnet werden " << endl;
        exit(-1);
    }

    lesen >> gebuchteplaetze;

    if(gebuchteplaetze > maxAnzahlPlaetze){
        cout << " Zu viele Passagiere " << endl;
    } else {

        lesen.get();

        int counter_;
        lesen >> counter_;

        string temp_name;
        int temp_nummer;


        for(int i = 0; i < gebuchteplaetze; i++){
            lesen >> temp_nummer;
            getline(lesen, temp_name);


            Passagier temp(temp_name,temp_nummer);
            passagier_vec.push_back(temp);
        }
        Passagier::setCounter(counter_);
    }

    lesen.close();
}

void Flug::data_write() {
    string quellname = "./" + this->abflug + "flugplaetze.txt";

    ofstream schreiben;
    schreiben.open(quellname.c_str(), ios::out);

    if(!schreiben) {
        cerr << quellname << " kann nicht geoeffnet werden " << endl;
        exit(-1);
    }

    schreiben << this->gebuchteplaetze << endl;
    schreiben << Passagier::getCounter() << endl;

    for(int i = 0; i < this->gebuchteplaetze; i++){
        schreiben << passagier_vec[i].getBuchungsnummer() << " " << passagier_vec[i].getName() << endl;
    }
    schreiben.close();
}
