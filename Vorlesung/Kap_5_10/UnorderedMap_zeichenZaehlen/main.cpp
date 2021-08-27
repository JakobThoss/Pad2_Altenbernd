#include <iostream>
#include <map>
using namespace std;

void befuellen(map<char,unsigned int> mm){
    string text = "Es war gegen elf Uhr morgens, Mitte Oktober, ein Tag ohne Sonne und mit klarer Sicht auf die Vorberge, was klatschkalten Regen verhieß. Ich trug meinen kobaltblauen Anzug mit dunkelblauem Hemd, Schlips und Brusttaschentuch, schwarze Sportschuhe und schwarze Wollsocken mit dunkelblauem Muster. Ich war scharf rasiert, sauber und nüchtern, egal nun, ob es einer merkte. Ich war haargenau das Bild vom gutgekleideten Privatdetektiv. Ich wurde von vier Millionen Dollar erwartet.";



    for(int i = 0; i < (int) text.length(); i++) {
        char temp = text[i];
        if((temp >= 65 && temp <= 90) || (temp >= 97 && temp <= 122)) {
            int anzahl = 1;


            map<char,unsigned int>::iterator found_it = mm.find(temp);
            if(found_it != mm.end()){
                anzahl = (*found_it).second;
                mm.erase(found_it);
                anzahl++;
            }
            mm.insert(make_pair(temp, anzahl));
        }
    }

    for(map<char,unsigned int>::iterator it = mm.begin(); it != mm.end(); it++){
        cout << (*it).first << " | " << (*it).second << endl;
    }

}


int main()
{
    map<char, unsigned int> test;
    befuellen(test);

    return 0;
}
