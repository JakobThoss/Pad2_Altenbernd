#include "rational.h"



int main()
{


    Rational test(1,3);
    Rational test2(1,2);

    bool wert = (test < test2);
    cout << boolalpha << wert << endl;

    return 0;
}
