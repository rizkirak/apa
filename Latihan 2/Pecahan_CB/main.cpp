#include <iostream>
#include "Pecahan.h"

using namespace std;

int main()
{
    int b,c,d;




    Pecahan a(1,15,4);
    a.keluaran();
    b=a.getBulat();
    cout<<"getBulat = "<<b<<endl;
    c=a.getPembilang ();
    cout<<"getPembilang = "<<c<<endl;
    d=a.getPenyebut ();
    cout<<"getPenyebut = "<<d<<endl;
    return 0;
}
