#include "stack.h"



int main()
{

    Stack test;
    cout << " leer? " << test.Empty() << endl;
    test.push(3.3);
    test.push(7.4);
    test.push(9.2);

    cout << "Top: " << test.top() << endl;

    test.pop();
    cout << "Top, nach Pop: " << test.top() << endl;

    cout << " leer? " << test.Empty() << endl;

    return 0;
}
