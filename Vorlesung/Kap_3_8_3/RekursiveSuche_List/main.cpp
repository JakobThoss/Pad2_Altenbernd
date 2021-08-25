#include <iostream>
#include <list>

using namespace std;

int rekursiv_search(int toFind, list<int> & l){
    if(l.empty()){
        return false;
    } else if(l.front() == toFind){
        return toFind;
    } else {
        l.pop_front();
        return rekursiv_search(toFind,l);
    }
}
int non_rekursiv_search(int toFind, list<int> & l) {

    bool gefunden = false;

    for(auto it = l.begin(); it != l.end(); ++it) {
        if(toFind == *(it)){
            gefunden = true;
        }
    }

    if(gefunden == false) {
        return false;
    } else {
        return toFind;
    }

}

int main()
{
     list <int> test;
     test.push_back(3);
     test.push_back(5);
     test.push_back(7);
     test.push_back(2);
     test.push_back(1);
     test.push_back(6);


     cout << " 0 = nicht gefunden " << endl;
     cout << " (nicht Rekursiv) Wert: " << non_rekursiv_search(7,test) << endl;
     cout << " (Rekursiv)       Wert: " << rekursiv_search(8,test) << endl;

    return 0;
}
