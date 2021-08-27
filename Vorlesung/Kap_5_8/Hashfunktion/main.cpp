#include <iostream>
#include <string>

using namespace std;

int hashfunction(int m, string k) {
   int h = 0;
    for(int i = 0; i < (int) k.length(); i++){
        h = (256 * h + ((int) k[i])) % m;
    }
    return h;
}

int main()
{

    string test = "A";
    cout << hashfunction(23,test) << endl;
    return 0;
}
