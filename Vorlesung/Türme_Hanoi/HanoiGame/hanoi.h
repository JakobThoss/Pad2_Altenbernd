#ifndef HANOI_H
#define HANOI_H
#include "turm.h"


const int anzahlTuerme = 3;

class Hanoi
{

private:
    int anzahlScheiben;
    Turm tuerme[3];
public:
    Hanoi(int p_anzahlscheiben) {
        anzahlScheiben = p_anzahlscheiben;

        tuerme[0].push(3);
        tuerme[0].push(2);
        tuerme[0].push(1);
    }

    void menue() {

        cout << "---------------------" << endl;
        cout << " (1) start game      " << endl;
    }

    void startGame() {

    }

    void befuellen(){

    }

    void ausgabe_tuerme() {

        Turm zwischenSpeicher[anzahlTuerme];

        string zeile = "";

        for (int i = anzahlScheiben; i > 0; i--){
            for(int j = 0; j < anzahlTuerme; j++) {
                if(i - tuerme[j].size() == 0) {
                    int temp = tuerme[j].top();
                    tuerme[j].pop();
                    zeile += " " + to_string(temp) + " ";
                    zwischenSpeicher[i].push(temp);
                } else {
                zeile += "     ";

            }

            cout << endl << endl;
        }

       for(int i = 0; i < anzahlTuerme; i++){
           int temp = zwischenSpeicher[i].top();
           zwischenSpeicher[i].pop();
           tuerme[i].push(temp);
       }

    }

};

#endif // HANOI_H
