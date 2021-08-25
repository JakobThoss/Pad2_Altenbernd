#include "queue.h"


int main()
{
    Queue test;
    cout << "Empty: " << test.Empty() << endl;

    test.Enq(4);
    test.Enq(6);
    test.Enq(8);

    cout << "Empty: " << test.Empty() << endl;

    cout << "Front: " << test.Front() << endl;

    test.Deq();
    cout << "Front: " << test.Front() << endl;
    return 0;
}
