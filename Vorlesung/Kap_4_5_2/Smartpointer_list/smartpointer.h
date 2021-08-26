#ifndef SMARTPTR_T
#define SMARTPTR_T

#include <cassert>
#include <iostream>
#include <cstddef>
#include <vector>

using namespace std;

const bool DEBUG = false;

struct reference
{
    int counter = 1;
    char * ptr;
};

vector<reference> benutzteSpeicheradressen;

int findeIndex(char * toFind){
    for(unsigned int i = 0; i<benutzteSpeicheradressen.size(); i++){
        if((char*) toFind == benutzteSpeicheradressen[i].ptr){
            return i;
        }
    }
    return -1;
}

template <typename T>
class Smartpointer
{

private:
    T * zeigerAufObjekt;

public:
    Smartpointer(T * p = nullptr) : zeigerAufObjekt(p)
    {
        if (zeigerAufObjekt != nullptr){

            int index = findeIndex((char*) p);

            // Speicherzelle von p ist noch nicht in Verwendung
            if(index == -1){
                reference r;
                r.counter = 1;
                r.ptr = (char*) p;
                benutzteSpeicheradressen.push_back(r);
            }
            // Speicherzelle von p ist bereits verwendet
            else{
                benutzteSpeicheradressen[index].counter++;
            }
        }
    }
    Smartpointer(const Smartpointer<T> & toCopy){
        *this = toCopy;
    }
    ~Smartpointer();
    T * operator->() const;
    T & operator*() const;
    Smartpointer & operator=(T * p);
    Smartpointer & operator=(const Smartpointer<T> & toAssign);
    operator bool() const;

    T * getZeiger() const {
        return zeigerAufObjekt;
    }
};


template <typename T>
inline Smartpointer<T>::~Smartpointer()
{
    if(zeigerAufObjekt == nullptr){
        if(DEBUG)
            cout << "mit nullzeiger destructed" << endl;
        return;
    }

    int index = findeIndex((char*)zeigerAufObjekt);

    if(index != -1){
        benutzteSpeicheradressen[index].counter--;

        if(benutzteSpeicheradressen[index].counter == 0){
            if(DEBUG)
                cout << "Inhalt: " << benutzteSpeicheradressen[index].counter << " Referenz-Count bei Null. Objekt wurde im Destruktor geloescht." << endl;
            delete zeigerAufObjekt;
            //  -> führt zu Segmentation Fault
            // benutzteSpeicheradressen.erase(benutzteSpeicheradressen.begin()+index);
        }
        else{
            if(DEBUG)
                cout << "Inhalt: " << benutzteSpeicheradressen[index].counter <<  "Referenz-Count groesser Null. Objekt still alive." << endl;
        }
    }
}

template <typename T>
inline T * Smartpointer<T>::operator->() const
{
    // Falls zeigerAufObekt == nullptr wäre so wird mit Fehlermeldung abgebrochen
    assert(zeigerAufObjekt);
    return zeigerAufObjekt;
}

template <typename T>
inline T & Smartpointer<T>::operator*() const
{
    // Falls zeigerAufObekt == nullptr wäre so wird mit Fehlermeldung abgebrochen
    assert(zeigerAufObjekt);
    return *zeigerAufObjekt;
}

template <typename T>
inline Smartpointer<T> & Smartpointer<T>::operator=(T * p)
{
    // (1) Suche Speicherzelle, auf die aktuelles Objekt zeigt und dekrementiere bzw. lösche, wenn sonst
    //     kein weiterer Smart-Pointer darauf zeigt

    int index = findeIndex((char*) zeigerAufObjekt);
    if(index != -1){
        benutzteSpeicheradressen[index].counter--;
        if(benutzteSpeicheradressen[index].counter == 0){
            if(DEBUG)
                cout << "Reference Count bei Null. Objekt in Zuweisungsoperator gelöscht." << endl;
            delete zeigerAufObjekt;
            // Eintrag in Reference-Vektor entfernen
            //  -> führt zu Segmentation Fault
            // benutzteSpeicheradressen.erase(benutzteSpeicheradressen.begin() + index);
        }
    }

    // (2) Lege den Zeiger um
    zeigerAufObjekt = p;
        // Sonderfall p == nullptr -> kein Reference Counting nötig
        if(p == nullptr){
            return *this;
        }

    // (3) Baue neuen Eintrag in reference-Vektor
    index = findeIndex((char*) zeigerAufObjekt);

    // Falls schon ein Eintrag für das, woraus p zeigt existiert
    if(index != -1){
        benutzteSpeicheradressen[index].counter++;
    }
    // Falls noch kein Eintrag für das worauf p zeigt existiert
    else{
        reference r;
        r.counter = 1;
        r.ptr = (char*) zeigerAufObjekt;
        benutzteSpeicheradressen.push_back(r);
    }

    return *this;
}

template <typename T>
inline Smartpointer<T>::operator bool() const
{
    // ist false, falls zeigerAufObjekt == nullptr
    return bool(zeigerAufObjekt);
}

template <typename T>
Smartpointer<T> & Smartpointer<T>::operator=(const Smartpointer<T> & toAssign){

    // Falls Zuweisung auf identische Objekte
    if(zeigerAufObjekt == toAssign.zeigerAufObjekt){
        return *this;
    }

    // (1) Suche Speicherzelle, auf die aktuelles Objekt zeigt und dekrementiere bzw. lösche, wenn sonst
    //     kein weiterer Smart-Pointer darauf zeigt

    int index = findeIndex((char*) zeigerAufObjekt);
    if(index != -1){
        benutzteSpeicheradressen[index].counter--;
        if(benutzteSpeicheradressen[index].counter == 0){
            if(DEBUG)
                cout << "Reference Count bei Null. Objekt in Zuweisungsoperator gelöscht." << endl;
            delete zeigerAufObjekt;
            // Eintrag in Reference-Vektor entfernen
            benutzteSpeicheradressen.erase(benutzteSpeicheradressen.begin() + index);
        }
    }

    // (2) Lege den Zeiger um
    this->zeigerAufObjekt = toAssign.zeigerAufObjekt;
        // Sonderfall p == nullptr -> kein Reference Counting nötig
        if(zeigerAufObjekt == nullptr){
            return *this;
        }

    // (3) Inkrementiere den Counter der Referenz, auf die er nun zeigt
    index = findeIndex((char*) zeigerAufObjekt);
    if(index != -1){
        benutzteSpeicheradressen[index].counter++;
    }
    else
        throw runtime_error("Fehler in operator= Index nicht gefunden!");

    return *this;
}

#endif
