#include "Point.h"
#include <iostream>

using namespace std;

int main()
{
    int c,d,e;

    Point a(1,2);
    a.keluaran();
    Point b(a);
    b.keluaran();
    c=a.GetAbsis();
    d=a.GetOrdinat();
    cout<<c<<endl;
    cout<<d<<endl;
    a.SetOrdinat(5);
    a.keluaran();
    b.keluaran();
    a.inverse();
    a.keluaran();
    b.inverse();
    b.keluaran();
    e=a.GetNbPoint();
    cout<<e<<endl;

    return 0;
}
