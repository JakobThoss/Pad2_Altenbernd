#include <iostream>

using namespace std;

const double epsilon = 0.00001;


double sqrt_with_do_loop(double a, const double precision) {
    //Precondition: a >= 0

    if(precision <= 0){
        throw runtime_error("Precision ist nicht positiv");
    }

    double x = 1.0, y, delta;

    do {
        y = 0.5 * (x + a / x);
        delta = y - x;
        x = y;

        if(x ==  0){
            throw runtime_error("Error: Sqrt falsch berechnet");
        }

    } while (abs(delta) > precision);

    return x;
}
int main() {
    double a;

    cout << "Bitte positive Zahl eingeben" << endl;
    cin >> a;

    try {
        if(!cin.good()){
            throw invalid_argument("Error: Kein Doublewert");
        }
        if(a < 0){
            throw invalid_argument("Error: Nenner < Null");
        }
        if(a == 0) {
            return 0;
        }
        cout << "Wurzel aus " << a << " ist " << sqrt_with_do_loop(a, epsilon) << endl;

    }  catch (runtime_error & exc) {
        cout << exc.what() << endl;
        return -1;
    }  catch (invalid_argument & exc) {
        cout << exc.what() << endl;
        return -1;
    }  catch (...) {
        cout << "Default exception caught " << endl;
        return -1;
    }



    return 0;
}
