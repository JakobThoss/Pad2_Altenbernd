#include "angebot.h"

int main()
{
 /*  Angebot test(3);
   Flug Berlin("Berlin", "Frankfurt", 3);
   Flug Hamburg("Hamburg", "Frankfurt", 4);
   Flug Muenchen("Muenchen", "Frankfurt", 5);

   test.menue();
*/

    Angebot test(3);
    test.data_read();
    test.menue();
    test.data_write();


}
