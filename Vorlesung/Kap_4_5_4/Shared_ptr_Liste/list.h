#ifndef LIST_H
#define LIST_H
#include <iostream>
#include <memory>

using namespace std;

struct knoten {
    int info;
    shared_ptr<knoten> next;
};


class List
{
private:
    shared_ptr<knoten> pos;
    shared_ptr<knoten> pre_pos;
    shared_ptr<knoten> anfang;

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
        return (pos == nullptr);
    }

    void adv() {
        if(pos != nullptr) {
            pre_pos = pos;
            pos = pos->next;
        }
    }

    void reset() {
        pos = anfang;
        pre_pos = nullptr;
    }

    void ins(int x) {
        shared_ptr<knoten> p(new knoten);

        p->info = x;
        p->next = pos;

        // Noch kein Element in der Liste drin
        if(anfang == nullptr){
            anfang = p;
        }
        // Es gibt einen Vorgänger
        if(pre_pos != nullptr){
            pre_pos->next = p;
        }
        else {
            anfang = p;
        }
        pos = p;
    }

    void del(){

        // Wenn Positionszeiger nicht am Ende steht (das heißt es gibt ein Element in der Liste) -> dann kann man nur löschen
        if(pos != nullptr) {
            // Positionszeiger steht nicht am Ende -> Es gibt einen Vorgänger
            if(pre_pos != nullptr) {
                pre_pos->next = pos->next;
            } else {
                anfang = pos->next;
            }

            if(pre_pos != nullptr) {
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
        weak_ptr<knoten> p = anfang;
        p.lock();

        cout << "Liste: ";

        while(p.lock()) {
            cout << p.lock()->info << " ";
            p = p.lock()->next;
        }
            cout << endl << endl;
    }

};

#endif // LIST_H
