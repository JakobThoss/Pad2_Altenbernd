#include "list.h"



int main()
{
    List test;
    test.ins(4);
    test.ins(7);
    test.ins(9);
    test.ins(2);
    test.ins(11);
    test.ins(16);

    cout << "Get = " << test.get() << endl;

    test.ausgeben();

    test.del();
    cout << "Get_after_del (standard) = " << test.get() << endl;

    test.adv();
    cout << "Get_after_adv = " << test.get() << endl;

    test.del();
    cout << "Get_after_del (nach adv) = " << test.get() << endl;

    test.reset();
    test.del();
    cout << "Get_after_del (nach reset) = " << test.get() << endl;

    test.ausgeben();
    return 0;
}
