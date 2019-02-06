#include <iostream>
#include "Tabel.h"

using namespace std;

int main()
{
    Tabel a;
    Tabel b=a;
    Tabel c;
    //a.keluaran();
    c=a;
    a.UData(10);
    a.keluaran();
    b.keluaran();
    c.keluaran();



    return 0;
}
