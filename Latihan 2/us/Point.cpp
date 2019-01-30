#include "Point.h"
#include <iostream>

using namespace std;

Point::Point()
{
    //ctor
    Data=new int[2];
    Data[0]=0;
    Data[1]=0;
    //NbPoint=6;
}

Point::Point(int x,int y)
{
    //ctor
    Data=new int[2];
    Data[0]=x;
    Data[1]=y;
    //NbPoint=6;
}

Point::Point(const Point &p)
{
    //ctor
    Data=new int[2];
    Data[0]=p.Data[0];
    Data[1]=p.Data[1];
}


Point::~Point()
{
    //dtor
    delete [] Data;
    //cout<<"dtor"<<endl;
}

int Point::GetAbsis()
{
    return Data[0];
}

int Point::GetOrdinat()
{
    return Data[1];
}



void Point::SetOrdinat(int Y)
{
    Data[1]=Y;
}


void Point::inverse()
{
    //Deklarasi Variabel
    int temp;

    //Algoritma

    temp=Data[0];
    Data[0]=Data[1];
    Data[1]=temp;
}

int Point::GetNbPoint()
{
    return NbPoint;
}






void Point::keluaran()
{
    cout<<Data[0]<<"dan"<<Data[1]<<endl;




}
