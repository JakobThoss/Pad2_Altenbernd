#include <iostream>

using namespace std;


    int max(int x, int y) { return x > y ? x : y; }
    int min(int x, int y) { return x < y ? x : y; }
    int add(int x, int y) { return x + y;  }

    int main() {
        int a = 1700, b = 1000;
        int (*fp)(int, int); // *fp ist Zeiger auf eine Funktion

        do {
            char c;
            cout << "Add (2)  max (1) oder min (0) ausgeben (sonst = Ende) ?";
            cin >> c;

            // Zuweisung von max() oder min() (ohne Klammern nach dem Funktionsnamen)
            switch (c) {
                case '0': fp = &min; break;
                case '1': fp = &max; break;
                case '2': fp = &add; break;
                default: fp = NULL;
            }
            if (fp) {
                // Dereferenzierung des Funktionszeigers und Aufruf
                cout << (*fp)(a, b) << endl;
                // oder auch direkte Verwendung des Namens (implizite Typumwandlung)
                cout << fp(a, b) << endl;
            }
        } while (fp);
        return 0;
    }




