#include <iostream>
#include "Point.h"
using namespace std;

int Point::NbPoint=0;
//int Point::GetNbPoint();


Point::Point()
{
    Data=new int[2];
    Data[0]=0;
    Data[1]=0;
    NbPoint++;
}

Point::Point(int x, int y)
{
    Data=new int[2];
    Data[0]=x;
    Data[1]=y;
    NbPoint++;
}

Point::Point(const Point& P)
{
    Data=new int[2];
    Data[0]=P.Data[0];
    Data[1]=P.Data[1];
    NbPoint++;
}

Point& Point::operator =(const Point& rhs)
{
    if (&rhs!=this)
    {
        Data[0]=rhs.Data[0];
        Data[1]=rhs.Data[1];
    }
    return *this;

    //cout<<"hancur"<<endl;
}

Point::~Point()
{
    delete [] Data;
    NbPoint--;
    //cout<<"hancur"<<endl;
}

int Point::GetAbsis()
{
    return Data[0];
    //cout<<"hancur"<<endl;
}



int Point::GetOrdinat()
{
    return Data[1];
    //cout<<"hancur"<<endl;
}


void Point::SetOrdinat(int a)
{
    Data[1]=a;
    //cout<<"hancur"<<endl;
}

void Point::inverse()
{
    int temp;
    temp=Data[0];
    Data[0]=Data[1];
    Data[1]=temp;

    //cout<<"hancur"<<endl;
}

int Point::GetNbPoint()
{
    return NbPoint;

    //cout<<"hancur"<<endl;
}

/*
Point::~Point()
{
    delete [] Data;//
    //cout<<"hancur"<<endl;
}



Point::~Point()
{
    delete [] Data;//
    //cout<<"hancur"<<endl;
}
*/

void Point::keluaran()
{
    cout<<Data[0]<<endl;
    cout<<Data[1]<<endl;
}

