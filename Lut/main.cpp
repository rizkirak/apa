#include <iostream>
#include "Point.h"
#include "Point3D.h"

using namespace std;

int main()
{
    Point a;
    a.keluaran();
    Point b(-1,3);
    b.keluaran();
    cout<<"Get"<<endl;
    cout<<b.GetAbsis()<<endl;
    cout<<b.GetOrdinat()<<endl;
    cout<<"Get"<<endl;
    Point c=b;
    Point d;
    d=c;
    c.keluaran();
    b.SetOrdinat(-10);
    d.keluaran();
    d.inverse();
    d.keluaran();
    cout<<Point::GetNbPoint()<<endl;

    //c.keluaran();
    
    Point3D f;
    f.keluaran();
    Point3D g(1,-10,100);
    g.keluaran();
    Point3D h=g;
    h.keluaran();
    cout<<"Get"<<endl;
    cout<<h.GetColor()<<endl;
    //cout<<b.GetOrdinat()<<endl;
    cout<<"Get"<<endl;
    h.SetColor(200);
    h.keluaran();
    h.inverse();
    h.keluaran();
    cout<<Point::GetNbPoint()<<endl;   
    
    
    

    return 0;
}
