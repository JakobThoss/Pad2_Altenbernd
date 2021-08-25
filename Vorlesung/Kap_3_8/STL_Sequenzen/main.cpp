#include <iostream>
#include <string>
#include <stack>
#include <queue>
#include <vector>
#include <list>
#include <algorithm>
#include <deque>
#include <array>

using namespace std;

template <typename T>
void eingabe(T & container) {
    for(int i = 0; i < 3; i++){
        cout << "Geben sie einen Namen an " << endl;
        string temp;
        cin >> temp;
        container.push_back(temp);
    }

    sort(container.begin(), container.end());

    for(auto it = container.begin(); it != container.end(); ++it){
        cout << *(it) << " ";
    }
    cout << endl;



}

int main() {

    cout << " (1) vector,  (2) list " << endl;
    cout << " Eingabe:  ";
    int temp;
    cin >> temp;
    cout << endl;

    if(temp == 1) {
        vector <string> v;
        eingabe(v);
    } else if(temp == 2) {

    }

    return 0;

}






