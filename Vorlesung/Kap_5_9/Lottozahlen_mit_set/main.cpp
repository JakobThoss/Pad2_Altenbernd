#include <iostream>
#include <set>
#include <iomanip>

using namespace std;

const int lottozahlen = 49;
const int auswahl = 6;

void lotto(set<int> s, set<int> gezogen) {
    for(int i = 0; i <= lottozahlen; i++) {
         s.insert(i);
    }

        srand(time(NULL));

    for(int i = 0; i < auswahl; i++){
        int zufall = rand() % s.size();

        auto it = s.begin();
        for(int j = 0; j < zufall; j++){
            it++;
        }

        gezogen.insert((*it));
        s.erase(it);


    }

    cout << "Gezogen: ";
    for(set<int>::iterator it = gezogen.begin(); it != gezogen.end(); ++it) {
        cout << *it << " ";
    }
    cout << endl << endl;

    cout << "Alle:  ";
    for(set<int>::iterator it = s.begin(); it != s.end(); ++it) {
        cout << *it << " ";
    }
    cout << endl;



}




int main()
{

    set<int> test;
    set<int> test2;
    lotto(test,test2);





    return 0;
}
