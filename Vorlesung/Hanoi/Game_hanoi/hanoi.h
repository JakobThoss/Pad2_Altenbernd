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
    Hanoi(int p_anzahlscheiben) : anzahlScheiben(p_anzahlscheiben) {
        for(int i = anzahlScheiben; i > 0; i++){
                    tuerme[i].push(i);
        }
    }

    void menue() {

        cout << "---------------------" << endl;
        cout << " (1) start game      " << endl;
    }

    void startGame() {}

    void ausgabe_tuerme() {

        Turm zwischenSpeicher[anzahlTuerme];



        for (int i = anzahlScheiben; i > 0; i--){
            string zeile = "";
            for(int j = 0; j < anzahlTuerme; j++) {
                if(i - tuerme[j].size() == 0) {
                    int temp = tuerme[j].top();
                    tuerme[j].pop();
                    zwischenSpeicher[i].push(temp);
                    zeile += " " + to_string(temp) + " ";

                } else {
                    zeile += "     ";

                }
            }
            cout << zeile << endl;
        }

        cout << " ---------------  " << endl;

        for(int i = 0; i < anzahlTuerme; i++){
            int temp = zwischenSpeicher[i].top();
            zwischenSpeicher[i].pop();
            tuerme[i].push(temp);
        }


    }

};

#endif // HANOI_H
