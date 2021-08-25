#include "stack.h"

int main()
{

    Stack <int,10> test;

    cout << "leer? " << test.empty() << endl;

    test.push(4);
    test.push(7);
    test.push(12);
    test.push(6);

    cout << "leer? " << test.empty() << endl;

    cout << "Top: " << test.top() << endl;
    test.ausgabe();

    test.pop();
    cout << "Top_after_del: " << test.top() << endl;
    test.ausgabe();


    return 0;
}
