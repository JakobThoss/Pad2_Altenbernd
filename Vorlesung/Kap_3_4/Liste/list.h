#ifndef LIST_H
#define LIST_H
#include <iostream>

using namespace std;

struct knoten {
    int info;
    knoten *next;
};


class List
{
private:
    knoten *pos;
    knoten *pre_pos;
    knoten *anfang;

public:
    List() {
        anfang = NULL;
        pos = NULL;
        pre_pos = NULL;
    }

    int get() {
        return pos->info;
    }

    bool end() {
        return (pos == NULL);
    }

    void adv() {
        if(pos != NULL) {
            pre_pos = pos;
            pos = pos->next;
        }
    }

    void reset() {
        pos = anfang;
        pre_pos = NULL;
    }

    void ins(int x) {
        knoten * p = new knoten;

        p->info = x;
        p->next = pos;

        // Noch kein Element in der Liste drin
        if(anfang == NULL){
            anfang = p;
        }
        // Es gibt einen Vorgänger
        if(pre_pos != NULL){
            pre_pos->next = p;
        }
        else {
            anfang = p;
        }
        pos = p;
    }

    void del(){

        // Wenn Positionszeiger nicht am Ende steht (das heißt es gibt ein Element in der Liste) -> dann kann man nur löschen
        if(pos != NULL) {
            // Positionszeiger steht nicht am Ende -> Es gibt einen Vorgänger
            if(pre_pos != NULL) {
                pre_pos->next = pos->next;
            } else {
                anfang = pos->next;
            }

            delete pos;

            if(pre_pos != NULL) {
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
        knoten * p = anfang;

        cout << "Liste: ";

        while(p != NULL) {
            cout << p->info << " ";
            p = p->next;
        }
            cout << endl << endl;
    }

};

#endif // LIST_H
