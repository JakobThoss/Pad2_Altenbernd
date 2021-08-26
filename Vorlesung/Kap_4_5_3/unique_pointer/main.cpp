#include <iostream>
#include <memory>

using namespace std;

// werteÜbergabe geht nicht , wegen Dopplung. Referenz funktioniert
void yallah(unique_ptr<int> & p_n) {
    cout << p_n << endl;
}

int main()
{



        // Funktionierendes Konstrukt
        unique_ptr<int> up(new int);
        // Funktionierendes Move
        unique_ptr<int> p_n = move(up);
        // Funktionierendes Array deklaration
        unique_ptr<int[]> pn(new int[4]);

        for(int i = 0; i < 4; i++){
            pn[i] = i + 1;
            cout << pn[i] << endl;
        }

        yallah(up);



    return 0;
}



