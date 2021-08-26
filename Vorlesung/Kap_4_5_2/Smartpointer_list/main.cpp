#include "list.h"



int main()
{
    List test;
    test.ins(5);
    test.ins(3);
    test.ins(4);

    test.ausgeben();

    test.del();

    test.ausgeben();

    test.adv();

    cout << test.get() << endl;
    return 0;
}
