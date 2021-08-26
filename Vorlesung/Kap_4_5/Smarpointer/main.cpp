#include "smarpointer.h"


int main()
{

    int * p = new int(5);
    Smarpointer<int> sm(p);

    int * x = new int(7);


    // Fehler 1 (Deref von nicht initialisierten Zeiger)
    try {
        Smarpointer<int> smp;
        cout << *smp << endl;
    }  catch (runtime_error & exc) {
        cout << exc.what() << endl;
    }

    try {
        Smarpointer<int> sp;

    }  catch () {

    } {

    // Fehler 5 (verwittwete Zeiger)
    try {
        sm = x;
    }  catch (runtime_error & exc) {
        cout << exc.what() << endl;
    }




    return 0;
}
