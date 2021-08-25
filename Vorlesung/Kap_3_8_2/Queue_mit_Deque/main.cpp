#include "queue.h"

using namespace std;

int main()
{
    Queue <int,10> test;
    test.enq(5);
    test.enq(4);
    test.enq(3);

    cout << "Front = " << test.front() << endl;

    test.deq();

    cout << "Front = " << test.front() << endl;

    return 0;
}
