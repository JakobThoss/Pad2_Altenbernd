#ifndef SMARPOINTER_H
#define SMARPOINTER_H
#include <iostream>
#include <cassert>

using namespace std;


template  <typename T>
class Smarpointer
{
private:
    T * ptr;
public:
    Smarpointer(T *p = nullptr) : ptr(p) {}

    ~Smarpointer() {
        delete ptr;
        ptr = nullptr;
    }

    // Wenn alle 5 Fehler umgangen sind, dann kommt der zeiger raus
    T * operator->() const {
        if(ptr == nullptr) {
            throw runtime_error("Nullpointer exception");
        }
        return ptr;
    }

    T & operator*() const {
        //Verwendung nur erlaubt, wenn interner Zeiger nicht der Nullpointer
        if(ptr == nullptr) {
            throw runtime_error("Nullpointer exception");
        }
        return *(ptr);
    }

    Smarpointer & operator =(T * p) {
        //Zuweisung nur erlaubt, wenn interner Zeiger noch nicht belegt ist
        if(ptr != nullptr)
        ptr = p;
        return *this;
    }
    operator bool() const {
        return bool (ptr);
    }

    void operator= (const Smarpointer & toAssign) = delete;

};

#endif // SMARPOINTER_H
