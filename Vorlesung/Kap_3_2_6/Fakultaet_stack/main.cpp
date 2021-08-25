#include <iostream>
#include <stack>

using namespace std;


long fak(int n) {
    stack <int> S;
    S.push(n);

    long result = 1;

    while(!S.empty()) {
        int a = S.top();

        S.pop();

        if(a != 1 ) {
            result *= a;
            S.push(a-1);
        }

    }

    return result;
}


int main()
{
    int n = 5;
    cout << "Fak " << n << ":  " <<  fak(n) << endl;

    return 0;
}
