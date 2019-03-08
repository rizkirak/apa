#include <iostream>
#include "Point3D.h"

using namespace std;

Point3D::Point3D()
{
    //Data=new int[2];
    c=new int[1];
    Data[0]=0;
    Data[1]=0;
    c[0]=0;
    //NbPoint++;
}





Point3D::Point3D(int x, int y, int color)
{
    //Data=new int[2];
    c=new int[1];
    Data[0]=x;
    Data[1]=y;
    c[0]=color;
    //NbPoint++;
}










Point3D::Point3D(const Point3D& P)
{
    //Data=new int[2];
    c=new int[1];
    Data[0]=P.Data[0];
    Data[1]=P.Data[1];
    c[0]=P.c[0];
    //NbPoint++;
}






Point3D::~Point3D()
{
    delete [] c;
    //cout<<"hancur"<<endl;
}







Point3D& Point3D::operator =(const Point3D& rhs)
{
    if (&rhs!=this)
    {
        Data[0]=rhs.Data[0];
        Data[1]=rhs.Data[1];
        c[0]=rhs.c[0];
    }
    return *this;
}


int Point3D::GetColor()
{
    return c[0];
}

void Point3D::SetColor(int color)
{
    c[0]=color;
    //cout<<"hancur"<<endl;
}

void Point3D::inverse()
{
    int temp;
    temp=Data[0];
    Data[0]=Data[1];
    Data[1]=temp;
    c[0]=(-1)*c[0];

    //cout<<"hancur"<<endl;
}









/*
Point::Point()
{
    Data=new int[2];
    Data[0]=0;
    Data[1]=0;
    NbPoint++;
}


Point::Point()
{
    Data=new int[2];
    Data[0]=0;
    Data[1]=0;
    NbPoint++;
}


Point::Point()
{
    Data=new int[2];
    Data[0]=0;
    Data[1]=0;
    NbPoint++;
}


Point::Point()
{
    Data=new int[2];
    Data[0]=0;
    Data[1]=0;
    NbPoint++;
}





Point3D();
Point(int x, int y);
Point(const Point& P);
virtual ~Point();
Point& operator =(const Point& rhs);
int GetAbsis();
int GetOrdinat();
void SetOrdinat(int a);
void inverse();
static int GetNbPoint();



void keluaran();
*/




void Point3D::keluaran()
{
    cout<<Data[0]<<endl;
    cout<<Data[1]<<endl;
    cout<<c[0]<<endl;
}
