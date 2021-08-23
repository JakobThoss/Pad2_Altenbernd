#include "zylinder.h"
#include "paket.h"
#include "kugel.h"

int main()
{
    Kugel test(3);
    Zylinder yallah(4);
    Paket mashallah(1,2,3);

    test.einpacken();
    yallah.einpacken();
    mashallah.einpacken();

    return 0;
}
