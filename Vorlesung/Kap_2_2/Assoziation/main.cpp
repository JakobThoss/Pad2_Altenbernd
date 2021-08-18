#include <iostream>
#include <vector>

using namespace std;

class Abonnent; //Vorwärtsdeklaration
class Zeitung {
public:
    void addAbonnent(Abonnent* abonnent) {
        abonnenten.push_back(abonnent);
    }
private:
    vector<Abonnent*> abonnenten;
};


class Abonnent {
public:
    void abonniere(const Zeitung * zeitung) {
        meineZeitungen.push_back((Zeitung*)zeitung);
    }
private:
    vector<Zeitung*> meineZeitungen;
};

int main(){
    return 0;
}
