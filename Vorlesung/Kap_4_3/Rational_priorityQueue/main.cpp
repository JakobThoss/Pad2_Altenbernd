#include "rational.h"
#include <queue>



int main()
{

    priority_queue<Rational> pq;
    Rational test(6,4);
    Rational test2(2,4);
    Rational ergebnis(4,4);

    pq.push(test);
    pq.push(test2);
    pq.push(ergebnis);
/*
    while (!pq.empty()){
        Rational temp;
        temp = pq.top();
        temp.ausgabe();
        pq.pop();
    }
*/
/*
    bool wert = (test < test2);
    cout << boolalpha << wert << endl;


    ergebnis  = test + test2;
    cout << " + = ";
    ergebnis.ausgabe();

    ergebnis = test * test2;
    cout << " * = ";
    ergebnis.ausgabe();
*/
    cout << test[0] << endl;
    cout << test[1] << endl;
    cout << test[2] << endl;

    return 0;
}
