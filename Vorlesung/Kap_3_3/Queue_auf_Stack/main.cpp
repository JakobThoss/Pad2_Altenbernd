#include "queue.h"


int main()
{
    Queue test;

    cout << "leer? " << test.empty() << endl;

    test.enq(5);
    test.enq(2);
    test.enq(7);

    cout << "leer? " << test.empty() << endl;

    cout << "front = " << test.front() << endl;

    test.deq();

    cout << "front = " << test.front() << endl;

    return 0;
}
