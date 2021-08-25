#include "stack.h"

int main()
{

    Stack <string,10> test;

    cout << "leer? " << test.empty() << endl;

    test.push("A");
    test.push("B");
    test.push("hallo");
    test.push("C");

    cout << "leer? " << test.empty() << endl;

    cout << "Top: " << test.top() << endl;
    test.ausgabe();

    test.pop();
    cout << "Top_after_del: " << test.top() << endl;
    test.ausgabe();


    return 0;
}
