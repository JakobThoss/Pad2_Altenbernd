#ifndef LIST_H
#define LIST_H
#include <iostream>
#include <smartpointer.h>

using namespace std;

struct knoten {
    int info;
    Smartpointer <knoten> next;
};


class List
{
private:
    Smartpointer<knoten> pos;
    Smartpointer<knoten> pre_pos;
    Smartpointer<knoten> anfang;

public:
    List() {
        anfang = nullptr;
        pos = nullptr;
        pre_pos = nullptr;
    }

    int get() {
        return pos->info;
    }

    bool end() {
        return (!pos);
    }

    void adv() {
        if(pos) {
            pre_pos = pos;
            pos = pos->next;
        }
    }

    void reset() {
        pos = anfang;
        pre_pos = nullptr;
    }

    void ins(int x) {
        knoten * temp = new knoten;
        Smartpointer<knoten> p(temp);

        p->info = x;
        p->next = pos;

        // Noch kein Element in der Liste drin
        if(!anfang){
            anfang = p;
        }
        // Es gibt einen Vorgänger
        if(pre_pos){
            pre_pos->next = p;
        }
        else {
            anfang = p;
        }
        pos = p;
    }

    void del(){

        // Wenn Positionszeiger nicht am Ende steht (das heißt es gibt ein Element in der Liste) -> dann kann man nur löschen
        if(pos) {
            // Positionszeiger steht nicht am Ende -> Es gibt einen Vorgänger
            if(pre_pos) {
                pre_pos->next = pos->next;
            } else {
                anfang = pos->next;
            }


            if(pre_pos) {
                //Positionszeiger steht auf ehemaligem Nachfolger
                pos = pre_pos->next;
            } else {
                pos = anfang;
            }
        } else {
            throw invalid_argument(" Es gibt kein Element in der Liste ");
        }
    }

    void ausgeben() {
        Smartpointer<knoten> p = anfang;


        cout << "Liste: ";

        while(p) {
            cout << p->info << " ";
            p = p->next;
        }
            cout << endl << endl;
    }

};

#endif // LIST_H
